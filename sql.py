import sqlite3

def search_user(username):
    # 连接到数据库
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()

    # 用户输入直接拼接到 SQL 查询中，容易发生 SQL 注入攻击
    query = f"SELECT * FROM users WHERE username = '{username}'"
    cursor.execute(query)

    # 获取查询结果
    result = cursor.fetchall()
    conn.close()

    return result

# 假设用户输入的是恶意字符串
user_input = "' OR '1'='1"
print(search_user(user_input))  # 这会返回所有用户，因为注入的条件 '1'='1' 总是为真
