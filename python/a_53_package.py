import test_package
from test_package.module_a import module_var_a

# from test_package import *


def main():
    print(test_package.module_a.module_var_a)
    test_package.module_a.module_a_func()
    print(test_package.module_b.module_var_b)
    print(test_package.module_b.Module_B())
    print(module_var_a)
    test_package.package_func()


if __name__ == "__main__":
    main()