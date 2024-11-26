import sqlite3

# 连接到数据库
def connect_db():
    conn = sqlite3.connect('users.db')
    return conn

# 创建一个简单的用户表（手动插入数据）
def create_table():
    conn = connect_db()
    cursor = conn.cursor()
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY,
        username TEXT NOT NULL,
        password TEXT NOT NULL
    )''')
    conn.commit()

    # 插入一些测试数据
    cursor.execute("INSERT INTO users (username, password) VALUES ('admin', 'admin123')")
    cursor.execute("INSERT INTO users (username, password) VALUES ('guest', 'guest123')")
    conn.commit()
    conn.close()

# 不安全的查询方法，存在 SQL 注入漏洞
def search_user(username):
    conn = connect_db()
    cursor = conn.cursor()

    # 拼接用户输入的 SQL 查询，存在 SQL 注入漏洞
    query = f"SELECT * FROM users WHERE username = '{username}'"
    cursor.execute(query)

    # 获取查询结果
    result = cursor.fetchall()
    conn.close()

    return result

# 创建数据库表并插入测试数据
create_table()

# 通过用户输入获取查询用户名
user_input = input("Enter username to search: ")

# 执行不安全的查询
result = search_user(user_input)

# 输出查询结果
if result:
    print("User found:", result)
else:
    print("User not found.")
