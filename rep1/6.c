#include <stdio.h>

int main(int argc, char *argv[])
{
    if (**argv == '.' && argc == 1)
    {
        printf("0\n");
    }
    else if (**argv == '.')
    {
        return main(0, argv + argc - 1);
    }
    else if (**(argv - 1) != '.')
    {
        return main(**argv - '0' + argc, argv - 1);
    }
    else if (**(argv - 1) == '.')
    {
        printf("%d\n", **argv - '0' + argc);
    }

    return 0;
}

/* 

    このプログラムでは, コマンドライン引数として渡された0個以上の1桁の整数列の和を,
    主にmain関数の再帰を用いて計算し, 表示している.

    整数列の個数が0個だった場合は, argcは1であり, **argvは'.'である.

    一見, argcの値が1であることのみを条件としても,
    数列の個数が0個である判定が出来るかのように思えるが,
    後述する整数列の個数が1個以上だった場合において,
    途中計算の結果を引数argcとして渡していくのだが,
    この時に偶然argcの値が1となる可能性があるため,
    ポインタargvの値がコマンドライン引数文字列の先頭を指していることの確認を,
    この場合の条件判定に採用している.

    この場合は, 整数列が存在しないため, 計算結果として0をターミナルに表示している.

    次に, 整数列の個数が1個だった場合について説明する.
    
    この場合では,
    argcを整数和の計算結果, argvを次の参照する数字へのポインタとして扱っている.

    具体的には, プログラムが実行された際に, main関数の再帰呼び出しの際に,
    引数argcを0として,
    argvをコマンドライン文字列の最後の数値へのポインタとして渡している.
    ここから再び, main関数の再帰呼び出しにより, 
    argvが整数列の最初の数値へのポインタとなるまで和の計算を繰り返す.
    main関数の引数として, argcは, argvの指す数値をint型数値に変換し,
    これをargcに足した値を渡し,
    argvは現在の数値の一つ前の数値へのポインタを引数として渡し,
    整数列の最後の数値から一つずつ前へargvをずらして参照している.

    argvが整数列の最初の数値を指した場合には,
    計算結果をターミナルに表示し, プログラムを終了する.
    計算終了判定を, 整数列の最初の数値で行うことで,
    プログラム起動時のargvの条件判定と衝突しないように工夫している.

*/