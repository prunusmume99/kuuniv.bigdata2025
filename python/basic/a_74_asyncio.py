import asyncio
import time

async def hello():
    print("hello world!")
    await asyncio.sleep(5.0)

def hello2():
    print("hello world!")
    time.sleep(5)

async def main():
    # for _ in range(3):
    #     await hello()                     # 동기

    # tasks = [hello(), hello(), hello()]
    # await asyncio.gather(*tasks)          # 비동기 실행

    task = [asyncio.create_task(hello()) for _ in range(3)]
    for task in task:
        await task
    print("main end")

if __name__ == "__main__":
    asyncio.run(main())
    