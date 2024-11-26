from flask import Flask, request, render_template_string, escape

app = Flask(__name__)

@app.route('/')
def home():
    return '''
        <form method="POST" action="/greet">
            Enter your name: <input type="text" name="username">
            <input type="submit" value="Greet me">
        </form>
    '''

@app.route('/greet', methods=['POST'])
def greet():
    username = request.form.get('username')
    # 漏洞：没有对用户输入进行过滤和转义
    return render_template_string(f'Hello, {escape(username)}!')
    
if __name__ == '__main__':
    import os
    debug_mode = os.getenv('FLASK_DEBUG', 'False').lower() in ['true', '1', 't']
    app.run(debug=debug_mode)
