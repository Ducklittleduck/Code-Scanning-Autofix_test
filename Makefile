# Makefile for Python project

# 设置Python解释器
PYTHON = python3

# 设置虚拟环境目录
VENV_DIR = venv

# 安装依赖
install:
	$(PYTHON) -m venv $(VENV_DIR)
	$(VENV_DIR)/bin/pip install -r requirements.txt

# 运行代码
run:
	$(PYTHON) sql.py

# 运行测试
test:
	$(PYTHON) -m unittest discover tests/

# 清理虚拟环境
clean:
	rm -rf $(VENV_DIR)

# 显示帮助信息
help:
	@echo "Usage:"
	@echo "  make install   - Set up virtual environment and install dependencies"
	@echo "  make run       - Run the Python code"
	@echo "  make test      - Run the tests"
	@echo "  make clean     - Remove the virtual environment"
	@echo "  make help      - Show this help message"
