from antlr4 import *
from forthLexer import forthLexer
from forthParser import forthParser
from forthVisitor import forthVisitor



class EvalVisitor(forthVisitor):
    
    def __init__(self):
        self.pila: list[int] = []
        self.aplica_op = {
            '.s': lambda: print(self.pila),
            '.': lambda: print(self.pila.pop()),
            '+': lambda: self.pila.append(self.pila.pop() + self.pila.pop()),
            '-': self._resta,
            '*': lambda: self.pila.append(self.pila.pop() * self.pila.pop()),
            '/': self._div,
            'mod': self._mod,
            'swap': self._swap,
            '2swap': self._two_swap,
            'dup': lambda: self.pila.append(self.pila[-1]),
            '2dup': lambda: self.pila.extend([self.pila[-2], self.pila[-1]]),
            'over': lambda: self.pila.append(self.pila[-2]),
            '2over': lambda: self.pila.extend([self.pila[-4], self.pila[-3]]),
            'rot': self._rot,
            'drop': lambda: self.pila.pop(),
            '2drop': self._two_drop,
            '=': self._equal,
            '<>': self._not_equal,
            '<': self._less_than,
            '<=': self._less_equal,
            '>': self._greater_than,
            '>=': self._greater_equal,
            'and': self._and,
            'or': self._or,
            'not': self._not,
        }
        self.funcions = {}
        self.funcions_act = []



    def visitRoot(self, ctx):
        try:
            for instr in ctx.instr():
                self.visit(instr)
        
        except IndexError as ie:
            print("Error: pila buida!")

        except ZeroDivisionError as zd:
            print("Error: intent de divisio per zero!")



    def visitFuncdef(self, ctx):
        nom = ctx.ID().getText()
        self.funcions[nom] = ctx.bloc()



    def visitNombre(self, ctx):
        num = int(ctx.NUM().getText())
        self.pila.append(num)



    def visitOperador(self, ctx):
        id = ctx.getChild(0).getText()

        if id in self.funcions : 
            self.funcions_act.append(id)
            self.visit(self.funcions[id])
            self.funcions_act.pop()
        elif id in self.aplica_op : self.aplica_op[id]()



    def visitRecurse(self, ctx):
        id = self.funcions_act[-1]
        self.visit(self.funcions[id])



    def visitCondicional(self, ctx):
        for atom in ctx.cond :
            self.visit(atom)
        
        if self.pila.pop() == -1: self.visit(ctx.bloc_if)
        elif ctx.bloc_else is not None: self.visit(ctx.bloc_else)




    # METODES PRIVATS


    def _resta(self):
        b = self.pila.pop()
        a = self.pila.pop()
        self.pila.append(a - b)



    def _div(self):
        b = self.pila.pop()
        if b == 0 : raise ZeroDivisionError()
        a = self.pila.pop()
        self.pila.append(a // b)



    def _mod(self):
        b = self.pila.pop()
        a = self.pila.pop()
        self.pila.append(a % b)



    def _swap(self):
        a, b = self.pila[-2], self.pila[-1]
        self.pila[-2], self.pila[-1] = b, a



    def _two_swap(self):
        a, b, c, d = self.pila[-4], self.pila[-3], self.pila[-2], self.pila[-1]
        self.pila[-4], self.pila[-3], self.pila[-2], self.pila[-1] = c, d, a, b



    def _rot(self):
        c, b, a = self.pila.pop(), self.pila.pop(), self.pila.pop()
        self.pila.append(b)
        self.pila.append(c)
        self.pila.append(a)



    def _two_drop(self):
        self.pila.pop()
        self.pila.pop()



    def _equal(self):
        a = self.pila.pop()
        b = self.pila.pop()
        self.pila.append(-1) if a == b else self.pila.append(0)



    def _not_equal(self):
        a = self.pila.pop()
        b = self.pila.pop()
        self.pila.append(-1) if a != b else self.pila.append(0)



    def _less_than(self):
        b = self.pila.pop()
        a = self.pila.pop()
        self.pila.append(-1) if a < b else self.pila.append(0)



    def _less_equal(self):
        b = self.pila.pop()
        a = self.pila.pop()
        self.pila.append(-1) if a <= b else self.pila.append(0)



    def _greater_than(self):
        b = self.pila.pop()
        a = self.pila.pop()
        self.pila.append(-1) if a > b else self.pila.append(0)



    def _greater_equal(self):
        b = self.pila.pop()
        a = self.pila.pop()
        self.pila.append(-1) if a >= b else self.pila.append(0)



    def _and(self):
        a = self.pila.pop()
        b = self.pila.pop()
        self.pila.append(-1) if a == -1 and b == -1 else self.pila.append(0)



    def _or(self):
        a = self.pila.pop()
        b = self.pila.pop()
        self.pila.append(-1) if a == -1 or b == -1 else self.pila.append(0)  



    def _not(self):
        a = self.pila.pop()
        self.pila.append(0) if a == -1 else self.pila.append(-1)  

