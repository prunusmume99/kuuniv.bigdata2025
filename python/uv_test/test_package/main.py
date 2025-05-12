# uv build
# pip install dist/uv_test-0.1.0-py3-none-any.whl
# test_package_main
# 옵션 uninstall -> pip uninstall uv_test


from .module_a import module_a_func, module_var_a
from .module_b import Module_B, module_var_b


def main():
    print(module_var_a)
    module_a_func()
    print(module_var_b)
    print(Module_B())
    print(module_var_a)


if __name__ == "__main__":
    main()