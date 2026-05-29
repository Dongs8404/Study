from tkinter import *
from tkinter import messagebox
from tkinter.simpledialog import *
from tkinter.filedialog import *

### 메뉴만들기 코드
# def func_open():
#     messagebox.showinfo("메뉴선택", "열기 메뉴를 선택함")

# def func_exit():
#     window.quit()
#     window.destroy()

#window = Tk()

# mainMenu = Menu(window)
# window.config(menu = mainMenu)

# fileMenu = Menu(mainMenu)
# mainMenu.add_cascade(label = "파일", menu = fileMenu)
# fileMenu.add_command(label = "열기", command = func_open)
# fileMenu.add_command(label = "종료", command = func_exit)

# window.mainloop()

### 화면에 입력창 띄우기 코드
# window = Tk()

# ## geometry > 화면크기설정
# window.geometry("400x100")

# label1 = Label(window, text = "입력된 값")
# label1.pack()

# ## 정수 입력창 띄우는 함수
# value = askinteger("확대배수", "주사위 숫자(1~6)을 입력하세요", minvalue = 1, maxvalue = 6)

# ## 라벨의 상태를 변경해주는 함수
# label1.configure(text = str(value))

# window.mainloop()

### 파일 오픈해서 그 파일 위치값을 출력해주는 코드
# window = Tk()
# window.geometry("400x100")

# label1 = Label(window, text = "선택된 파일 이름")
# label1.pack()

# ## 파일 이름 물어보는 함수
# filename = askopenfilename(parent = window, filetypes = (("GIF 파일", "*.gif"), ("모든 파일", "*.*")))

# label1.configure(text = str(filename))
# window.mainloop()

### 대화상자 코드
# window = Tk()
# window.geometry("400x100")

# label1 = Label(window, text = "선택된 파일 이름")
# label1.pack()

# ## askaverasfile() vs asksaveaasfilename() 차이 
# saveFp = asksaveasfile(parent=window, mode = "w", defaultextension=".jpg", filetypes = (("JPG파일", "*.jpg;*.jpeg"),("모든 파일", "*.*")))
# label1.configure(text = saveFp)
# ## saveFp는 단순 문자열이 아닌 파일 객체가 들어감
# saveFp.close()

### file open(GIF, ALL)해서 Tk화면창에 이미지 띄우는 코드
# def func_open():
#     filename = askopenfilename(parent= window, filetypes=(("GIF 파일", "*.gif"),("모든 파일", "*.*")))
#     photo = PhotoImage(file = filename)
#     pLabel.configure(image = photo)
#     pLabel.image = photo

# ## 이미지 전체 회색으로 만드는코드 > PhotoImage는 for문으로 픽셀마다 변경, 오래걸림
#     for x in range(photo.width()):
#         for y in range(photo.height()):
#             r, g, b = photo.get(x, y)
#             gray = (r + g + b) // 3
#             photo.put("#%02x%02x%02x" % (gray, gray, gray), (x, y))

# def func_exit():
#     window.quit()
#     window.destroy()

# window = Tk()
# window.geometry("500x500")
# window.title("명화 감상하기")

# photo = PhotoImage()
# pLabel = Label(window, image = photo)
# pLabel.pack(expand= 1, anchor=CENTER)

# mainMenu = Menu(window)
# window.config(menu = mainMenu)
# fileMenu = Menu(mainMenu)
# mainMenu.add_cascade(label = "파일", menu = fileMenu)
# fileMenu.add_command(label = "파일 열기", command=func_open)
# fileMenu.add_command(label = "프로그램 종료", command= func_exit)

# window.mainloop()

###영상처리기본
# def loadImage(fname):
#     global inImage, XSIZE, YSIZE
#     fp = open(fname, 'rb')

#     for i in range(0, XSIZE):
#         tmpList = []
#         for k in range(0, YSIZE):
#             data = int(ord(fp.read(1)))
#             tmpList.append(data)
#         inImage.append(tmpList)

#     fp.close()

# def displayImage(image):
#     global XSIZE, YSIZE
#     rgbString = ""
#     for i in range(0, XSIZE):
#         tmpString = ""
#         for k in range(0 , YSIZE):
#             data = image[i][k]
#             tmpString += "#%02x%02x%02x " % (data, data, data)
        
#         rgbString += "{" + tmpString + "} "

#     paper.put(rgbString)

# window = None
# canvas = None
# XSIZE, YSIZE = 256, 256
# inImage = []

# window = Tk()
# window.title("흑백 사진 보기")
# canvas = Canvas(window, height = XSIZE, width= YSIZE)
# paper = PhotoImage(width=XSIZE, height= YSIZE)
# canvas.create_image((XSIZE / 2, YSIZE / 2), image = paper, state = "normal")

# filename = "./files/RAW/cat256.raw"
# loadImage(filename)

# displayImage(inImage)

# canvas.pack()
# window.mainloop()


###CSV파일 처리
def printList(pList):
    for data in pList:
        print(data, end='\t')
    print()

with open("./files/CSV/singer1.csv", "r") as inFp:
    header = inFp.readline()
    header = header.strip()
    header_list = header.split(',')
    printList(header_list)
    for inStr in inFp:
        inStr = inStr.strip()
        row_list = inStr.split(',')
        printList(row_list)

