from antlr4.error.ErrorListener import ErrorListener
from eval import *


class CollectErrors(ErrorListener):
    def __init__(self):
        self.n = 0


    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        self.n += 1


def interpret(expr : str) -> None :
    input_stream = InputStream(expr)
    lexer = forthLexer(input_stream)
    err = CollectErrors()
    lexer.removeErrorListeners()
    lexer.addErrorListener(err)
    token_stream = CommonTokenStream(lexer)
    parser = forthParser(token_stream)
    parser.removeErrorListeners()
    parser.addErrorListener(err)
    tree = parser.root()
    if err.n == 0 :
        visitor = EvalVisitor()
        visitor.visit(tree)
    else :
        print(err.n, 'errors de sintaxi.')