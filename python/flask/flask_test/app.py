# flask run  -> 웹 공부하고 싶으면 검색
# 웹 프레임 워크 / 백엔드 -> 핸드폰으로 연동 가능
    
# jdango flask fastapi..
# gradio (머신러닝.. stable diff, open UI)
# streamlit (대시보드 깔끔) -> 핸드폰 연동 가능
# Dash (데이터 시각화)      -> 핸드폰 연동 가능

# GUI 프로그램
# pythonQT, tkinter -> window 프로그램
# pygame, matplotlib, openCV
# windows OS -> (C# MSC(C++)), linux -> SDL, vulkan
# unity, unreal

# AI 관련 라이브러리
# numpy, pandas, matplotlib, tensorflow ( keras ), pytorch, sk-learn(머신러닝)
# orange3



from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello():
    return "<hi> Hello, world! I'm Python Flask!!<hi>"

# 웹 호스팅 하고 확인하는 코드 