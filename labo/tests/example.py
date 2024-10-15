# ANSIエスケープシーケンスを使って色付きの文字を表示する関数
def print_colored(text, foreground=None, background=None, bold=False, underline=False):
    # ANSIエスケープシーケンスの構成
    code = "\033["

    # 太字を指定する場合
    if bold:
        code += "1;"
    # 下線を指定する場合
    if underline:
        code += "4;"

    # 前景色（文字の色）
    if foreground:
        code += f"{foreground};"
    
    # 背景色
    if background:
        code += f"{background};"
    
    # 最後のセミコロンを削除して、閉じる
    if code.endswith(";"):
        code = code[:-1]

    # エスケープシーケンスの終了
    code += "m"
    
    # テキストの後で色設定をリセット
    reset = "\033[0m"
    
    print(f"{code}{text}{reset}")

# 色コード
colors = {
    "black": 30,
    "red": 31,
    "green": 32,
    "yellow": 33,
    "blue": 34,
    "magenta": 35,
    "cyan": 36,
    "white": 37
}

# 背景色コード
bg_colors = {
    "black": 40,
    "red": 41,
    "green": 42,
    "yellow": 43,
    "blue": 44,
    "magenta": 45,
    "cyan": 46,
    "white": 47
}

# いろいろな文字の出力
print_colored("これは赤い文字です", foreground=colors["red"])
print_colored("これは青い文字で黄色の背景です", foreground=colors["blue"], background=bg_colors["yellow"])
print_colored("これは太字の緑の文字です", foreground=colors["green"], bold=True)
print_colored("これは下線付きのマゼンタ色の文字です", foreground=colors["magenta"], underline=True)
print_colored("これは黒い背景の白い文字です", foreground=colors["white"], background=bg_colors["black"])
