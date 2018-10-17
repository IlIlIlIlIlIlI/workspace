import random

def guess_number():
    num = random.randint(1, 100)
    is_done = False
    cnt = 0
    while not is_done:
        guess = int(input('请输入一个[1， 100]的整数：'))
        if guess == num:
            is_done = True
        elif guess > num:
            print('大了，再猜一遍！')
        elif guess < num:
            print('小了，再猜一遍！')
        cnt += 1
    print('恭喜你，猜了%d次，终于猜对了！答案是%d！' %(cnt, num))

def loop():
    guess_number()
    restart = input('重新开始请按"y", 退出请按"n"：')
    return restart

def main():
    while loop() == 'y':
            loop()

main()