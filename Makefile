# Makefile for SQLite3 example project

# 设置Python解释器
PYTHON = python3

# 运行代码
run:
	$(PYTHON) sql.py

# 清理任何临时文件（如果有）
clean:
	rm -rf __pycache__

# 显示帮助信息
help:
	@echo "Usage:"
	@echo "  make run       - Run the main Python code"
	@echo "  make clean     - Remove any temporary files (e.g., __pycache__)"
	@echo "  make help      - Show this help message"
