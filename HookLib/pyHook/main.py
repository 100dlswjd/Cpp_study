import sys 
import ctypes
from ctypes import wintypes, windll
import win32con
from PySide6.QtCore import Slot
from PySide6.QtWidgets import QApplication, QMainWindow, QTableWidgetItem
from main_from import Ui_MainWindow

KEYBOARD_HOOK =	0x00000001
MOUSE_HOOK	=	0x00000002
WM_KEYHOOK	=	win32con.WM_USER + 1
WM_MOUSEHOOK =	win32con.WM_USER + 2

class Mainwindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(Mainwindow, self).__init__()
        self._hook_dll = windll.LoadLibrary("C:\\Users\\in\\Desktop\\github\\100dlswjd\\Cpp_study\\HookLib\\x64\\Debug\\HookDLL.dll")
        self._InstallHook = self._hook_dll["InstallHook"]
        self._InstallHook.argtypes = (wintypes.HWND, wintypes.DWORD)
        self._InstallHook.restype = wintypes.BOOL
        
        self._UnInstallHook = self._hook_dll["UnInstallHook"]
        self._UnInstallHook.argtypes = (wintypes.DWORD, )
        self._UnInstallHook.restype = wintypes.BOOL
        
        self._installed = False

        self.setupUi(self)
        self.tableWidget.setColumnCount(3)
        self.tableWidget.setHorizontalHeaderLabels(["메시지 타입", "wParam", "lParam"])
        self.pushButton.clicked.connect(self.pushButton_handler)
        
    def insert_item(self, msg: int, wParam : int , lParam : int):
        cur_count = self.tableWidget.rowCount()
        self.tableWidget.setRowCount(cur_count+1)

        for idx, data in enumerate([msg, wParam, lParam]):
            item = QTableWidgetItem()
            item.setText(str(data))
            self.tableWidget.setItem(cur_count, idx, item)

    @Slot()
    def pushButton_handler(self):
        """
        cur_count = self.tableWidget.rowCount()
        self.tableWidget.setRowCount(cur_count+1)

        item = QTableWidgetItem()
        item.setText("따따따땄쮜")
        self.tableWidget.setItem(cur_count, 0, item)
        """
        print("push !")
        if self._installed:
            self._UnInstallHook(KEYBOARD_HOOK | MOUSE_HOOK)
        else:
            result = self._InstallHook(self.winId(), KEYBOARD_HOOK | MOUSE_HOOK)
            if result == win32con.FALSE:
                print("설치 실패 1!!")
                return

        self._installed = not self._installed
        self.pushButton.setText("중지" if self._installed else "시작")
    def nativeEvent(self, eventType, message: int):
        if eventType == "windows_generic_MSG":
            msg = wintypes.MSG.from_address(message.__int__())
            if msg.message == WM_KEYHOOK or msg.message == WM_MOUSEHOOK:
                self.insert_item(msg.message, msg.wParam, msg.lParam)
            
        self.tableWidget.scrollToBottom()

        return super().nativeEvent(eventType, message)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Mainwindow()
    window.show()
    app.exec()