# sudo python3 setup2.py bdist_wheel
# pip install dist/test_package-0.1.0-py3-none-any.whl
# 테스트 -> test_package_main
# pip uninstall test_package

from setuptools import setup

setup(
    name="test_package",
    version="0.1.0",
    description="간단한 패키지 실습 코드",
    packages=["test_package"],
    entry_points={"console_scripts": ["test_package_main = test_package:main"]},
    include_package_data=True,
    zip_safe=False,
)


# poetry
# uv