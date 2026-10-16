from ply.lex import lex
from ply.yacc import yacc
import sys


global lineNumber

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python TP2.py <filename> <line_number>")
        sys.exit(1)

    lineNumber = 0

    tokens = ("OPEN_PAREN", "CLOSE_PAREN", "PLUS", "MINUS", "MULT", "DIV", "NUMBER", "NAME", "EQUAL")
    t_ignore_COMMENT = r'\#.*' # https://ply.readthedocs.io/en/latest/ply.html#discarded-tokens
    t_ignore_SPACE = r'\s+'
    t_OPEN_PAREN = r'\('
    t_CLOSE_PAREN = r'\)'
    t_PLUS = r'\+'
    t_MINUS = r'\-'
    t_MULT = r'\*'
    t_DIV = r'\/'
    t_EQUAL = r'\='
    t_NAME = r'[a-zA-Z_][a-zA-Z0-9_]*'

    def t_NUMBER(t):
        r"""\d+(\.\d+)?"""
        t.value = float(t.value)
        return t

    def t_ignore_NEWLINE(t):
        r"""\n"""
        t.lexer.lineno += 1

    def t_error(t):
        print(f'Illegal character {t.value[0]!r}')
        t.lexer.skip(1)

    lexer = lex()
    
    ### GRAMMAR ###
    ########################

    # https://ply.readthedocs.io/en/latest/ply.html#dealing-with-ambiguous-grammars
    precedence = (
        ('left', 'PLUS', 'MINUS'),
        ('left', 'MULT', 'DIV'),
    )

    def p_error(p):
        if hasattr(p, "value"):
            print(f'Syntax error at {p.value!r}')
        else:
            print("Error", p)
    """
    G = {{S, T}, {+, -, *, /, number,(,)}, T, R}, où R :
    T → name = S | S = name | S
    S → (S) | S + S | S - S | S * S | S / S | number
    """
    def p_T(p):
        """T : NAME EQUAL S"""
        p[0] = ("assignment", p[1], p[3])

    def p_T_inverse(p):
        """T : S EQUAL NAME"""
        p[0] = ("assignment", p[3], p[1])

    def p_T_S(p):
        """T : S"""
        p[0] = p[1]

    def p_S(p):
        """S : OPEN_PAREN S CLOSE_PAREN"""
        p[0] = ("grouped", p[2])

    def p_S_operation(p):
        """S : S PLUS S
             | S MINUS S
             | S MULT S
             | S DIV S"""
        p[0] = (p[2], p[1], p[3])

    def p_S_number(p):
        """S : NUMBER"""
        p[0] = ("number", p[1])

    def p_S_minus(p):
        """S : MINUS S"""
        p[0] = ("unary", p[1], p[2])

    ### FILE ###
    ########################
    
    parser = yacc()
    file = open(sys.argv[1], "r")
    program = file.read()
    print(program)
    ast = parser.parse(program)
    print(ast)

    ### TRANSLATION ###
    ########################