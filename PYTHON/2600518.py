# import xlrd

# workbook = xlrd.open_workbook(("./files/EXCEL/singer.xls"))
# sheetCount = workbook.nsheets

# personNum = 0
# personIdx = 2
# rowCount = 0
# wsheetList = workbook.sheets()
# for worksheet in wsheetList:
#     rowCount += worksheet.nrows-1
#     for row in range(1, worksheet.nrows):
#         personNum += int(worksheet.cell_value(row, personIdx))

# print("전체 가수그룹 인원 합계: ", personNum)
# print("가수그룹 인원 평균 : ", personNum/rowCount)

##--------------------------------------------------------------------------

# import xlrd
# import xlwt

# workbook = xlrd.open_workbook(("./files/EXCEL/singer.xls"))
# outWorkbook = xlwt.Workbook()

# wsheetList = workbook.sheets() #sheet들을 list로 받아옴
# outSheet = outWorkbook.add_sheet("singer")
# worksheet = wsheetList[0]
# idx = 2
# for col in range(worksheet.ncols): #헤더가져오기
#     outSheet.write(0, col, worksheet.cell_value(0, col))

# totalRow = 0
# for worksheet in wsheetList: #내용가져오기
#     for row in range(1, worksheet.nrows):
#         personnel = worksheet.cell_value(row, idx)
#         if int(personnel) >= 6:
#             totalRow += 1
#             for col in range(worksheet.ncols):
#                 outSheet.write(totalRow, col, worksheet.cell_value(row, col))

# outWorkbook.save("./files/EXCEL/outSinger3.xls")
# print("Save. OK~")

##--------------------------------------------------------------------------
from tkinter import *
import xlsxwriter

window = Tk()
photo = PhotoImage(file = "./files/GIF/pic7.gif")
h = photo.height()
w = photo.width()
print("이미지 크기 : ", h, 'x', w)

photoR = [ [0 for _ in range(h)] for _ in range(w)]
photoG = [ [0 for _ in range(h)] for _ in range(w)]
photoB = [ [0 for _ in range(h)] for _ in range(w)]

for i in range(w):
    for k in range(h):
        r, g, b = photo.get(i, k)
        photoR[i][k] = r
        photoG[i][k] = g
        photoB[i][k] = b

workbook = xlsxwriter.Workbook("./files/EXCEL/picture06_art.xlsx")
#worksheetRGB = workbook.add_worksheet("photoRGB")
worksheetR = workbook.add_worksheet("photoRed")
worksheetG = workbook.add_worksheet("photoBlue")
worksheetB = workbook.add_worksheet("photoGreen")

for worksheet in [worksheetR, worksheetG, worksheetB]:
    worksheet.set_column(0, w-1, 1.0)
    
    for i in range(h):
        worksheet.set_row(i, 9.5)

    for i in range(w):
        for k in range(h):
            hexR = hex(photoR[i][k])
            hexG = hex(photoG[i][k])
            hexB = hex(photoB[i][k])
            hexStr = '#'

            if worksheet.name != "photoRed":
                hexStr += '00'
            elif len(hexR[2:]) < 2:
                hexStr += '0' + hexR[2:]
            else:
                hexStr += hexR[2:]
            
            if worksheet.name != "photoGreen":
                hexStr += '00'
            elif len(hexG[2:]) < 2:
                hexStr += '0' + hexG[2:]
            else:
                hexStr += hexG[2:]

            if worksheet.name != "photoBlue":
                hexStr += '00'
            elif len(hexB[2:]) < 2:
                hexStr += '0' + hexB[2:]
            else:
                hexStr += hexB[2:]

            cell_format = workbook.add_format()
            cell_format.set_bg_color(hexStr)
            worksheet.write(k, i, '', cell_format)

workbook.close()
print("Save. OK~")
#print("[50][50] 위치의 RGB 값 : ", photoR[50][50], photoG[50][50], photoB[50][50])