from flask import Flask, request, jsonify
import pandas as pd
import os

app = Flask(__name__)

USERS_FILE = 'users.csv'

def verify_user(username, password):
    if os.path.exists(USERS_FILE):
        df = pd.read_csv(USERS_FILE)
        user = df[(df['username'] == username) & (df['password'] == password)]
        return not user.empty
    return False

def register_user(username, password, email):
    if os.path.exists(USERS_FILE):
        df = pd.read_csv(USERS_FILE)
        if username in df['username'].values:
            return False
    else:
        df = pd.DataFrame(columns=['username', 'password', 'email'])

    new_data = pd.DataFrame({'username': [username], 'password': [password], 'email': [email]})
    df = pd.concat([df, new_data], ignore_index=True)
    df.to_csv(USERS_FILE, index=False)
    return True

@app.route('/register', methods=['POST'])
def register():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    email = data.get('email')
    if username and password and email:
        if register_user(username, password, email):
            return jsonify({"status": "success", "message": "User registered successfully."})
        else:
            return jsonify({"status": "error", "message": "User already exists."}), 409
    return jsonify({"status": "error", "message": "Missing username, password or email."}), 400

@app.route('/login', methods=['POST'])
def login():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    if username and password:
        if verify_user(username, password):
            return jsonify({"status": "success", "message": "Login successful."})
        else:
            return jsonify({"status": "error", "message": "Invalid username or password."}), 401
    return jsonify({"status": "error", "message": "Missing username or password."}), 400

if __name__ == '__main__':
    app.run(debug=True)