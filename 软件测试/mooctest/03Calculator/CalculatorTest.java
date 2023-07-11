package net.mooctest;

import static org.junit.Assert.*;

import org.junit.Test;




public class CalculatorTest {
	
	Calculator c= new Calculator();
	
	@Test
	public void testCommand() {
		CommandNotFoundException e =new CommandNotFoundException("c");
		assertEquals("c", e.getCommand());
		
		ExpressionParserException exception= new ExpressionParserException("eee");
		assertEquals("eee", exception.getFaultyExpression());
		
		FunctionNotFoundException ffException =new FunctionNotFoundException("ff");
		assertEquals("ff", ffException.getFunc());
		
		MissingOperandException mm = new MissingOperandException("an", "+");
		assertEquals("+", mm.getOperator());
		
		UnmatchedBracketsException unmatchedBracketsException= new UnmatchedBracketsException("ab", 1);
		assertEquals(1, unmatchedBracketsException.getIndexOfBracket());
		
		VariableNotFoundException vv1 =new VariableNotFoundException("vva");
		assertEquals("vva", vv1.getVar());
		
		VariableNotFoundException vv2 =new VariableNotFoundException("v","vva");
		assertEquals("vva", vv1.getVar());
		
	}
	


	@Test(expected=NullExpressionException.class)
	public void testEvaluate00() throws Throwable {
		Calculator.expParser=new ExpressionParser(2);
		Calculator.evaluate("");

	}
	
	@Test
	public void testEvaluate01() throws Throwable {
		Calculator.expParser=new ExpressionParser(2);
		
//		String ass="(\\s+)?(\\w+)(\\s+)(=)(.*)";
//		
//		System.out.println("正则匹配：");
//		System.out.println(" 3 = 3".matches(ass));
		
		Calculator.evaluate("8");
		Calculator.evaluate(" 8 = 8");
		Calculator.parseCommand("list vars");

	}
	
	@Test(expected=ExpressionParserException.class)
	public void testEvaluate02() throws Throwable {
		Calculator.expParser=new ExpressionParser(2);
		Calculator.evaluate("1+2=3");
//		Calculator.evaluate("1+2/0");
	}
	
	@Test
	public void testEvaluate03() throws Throwable {
		Calculator.expParser=new ExpressionParser(2);
        //Calculator.expParser.numberOfVars=2;
		String exp="8 = 8";
//		String  vn=exp.substring(0, exp.indexOf("=")).trim();
//		String vv="" + Double.parseDouble(exp.substring(exp.indexOf("=") + 1));
//		System.out.println("vn="+vn+"  vv= "+vv);
		Calculator.evaluate(exp);
		Calculator.expParser.addVariable("8", "10");
		Calculator.expParser.addVariable("9", "10");
		
	}
	

	@Test
	public void testParseCommand00() throws Throwable {
		 Calculator.parseCommand("exit");
		 Calculator.parseCommand("help");
		 Calculator.parseCommand("help vars");
		 Calculator.parseCommand("help cmds");
		 Calculator.parseCommand("help funcs");
		 Calculator.parseCommand("list");
		 Calculator.parseCommand("list cmds");
		 //Calculator.parseCommand("list vars");
		 Calculator.parseCommand("list funcs");
	}
	
	@Test(expected=CommandNotFoundException.class)
	public void testParseCommand01() throws Throwable {
		 Calculator.parseCommand("nono");
		 //assertTrue("nono"==Calculator.parseCommand("nono").getCommand());
	}
	
	@Test
	public void testMathParserFactorial() {
		Calculator.expParser = new ExpressionParser(10);
		assertEquals(1, Calculator.expParser.factorial(1),0);
		assertEquals(2, Calculator.expParser.factorial(2),0);
		
		assertEquals(16, Calculator.expParser.solveBinaryOperation(4, "^", 2),0);
		assertEquals(0, Calculator.expParser.solveBinaryOperation(4, "%", 2),0);
		assertEquals(2, Calculator.expParser.solveBinaryOperation(4, "/", 2),0);
		assertEquals(8, Calculator.expParser.solveBinaryOperation(4, "*", 2),0);
		assertEquals(6, Calculator.expParser.solveBinaryOperation(4, "+", 2),0);
		assertEquals(2, Calculator.expParser.solveBinaryOperation(4, "-", 2),0);
		assertEquals(0, Calculator.expParser.solveBinaryOperation(4, "--", 2),0);
		
		
	}
	
	@Test
	public void testMathParserSolveUnaryFunction00() throws Throwable {
//		System.out.println("s");
//		System.out.println(Calculator.expParser.solveUnaryFunction("sin", 30));
		assertEquals(Math.sin(30), Calculator.expParser.solveUnaryFunction("sin", 30),0);
		assertEquals(Math.cos(30), Calculator.expParser.solveUnaryFunction("cos", 30),0);
		assertEquals(Math.tan(30), Calculator.expParser.solveUnaryFunction("tan", 30),0);
		
		assertEquals(1.0/Math.sin(30), Calculator.expParser.solveUnaryFunction("csc", 30),0);
		assertEquals(1.0/Math.cos(30), Calculator.expParser.solveUnaryFunction("sec", 30),0);
		assertEquals(1.0/Math.tan(30), Calculator.expParser.solveUnaryFunction("ctn", 30),0);
		
		assertEquals(Math.toRadians(30), Calculator.expParser.solveUnaryFunction("rad", 30),0);
		assertEquals(Math.toDegrees(30), Calculator.expParser.solveUnaryFunction("deg", 30),0);
		assertEquals(Calculator.expParser.factorial(30), Calculator.expParser.solveUnaryFunction("fct", 30),0);
		
		assertEquals(Math.abs(30), Calculator.expParser.solveUnaryFunction("abs", 30),0);
		assertEquals(Math.exp(30), Calculator.expParser.solveUnaryFunction("exp", 30),0);
		assertEquals(Math.log(30), Calculator.expParser.solveUnaryFunction("log", 30),0);
	}
	
	@Test(expected=FunctionNotFoundException.class)
	public void testMathParserSolveUnaryFunction01() throws Throwable {
		assertEquals(Math.sin(30), Calculator.expParser.solveUnaryFunction("ssin", 30),0);

	}
	
	@Test
	public void testExpParseVariables00() throws Throwable {
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.numberOfVars=1;
		Calculator.expParser.parseVariables("1+3");
		Calculator.expParser.parseVariables("<1+3");
		Calculator.expParser.parseVariables(">1+3<");
		
	}
	
	@Test(expected=VariableNotFoundException.class)
	public void testExpParseVariables01() throws Throwable {
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.numberOfVars=1;
		Calculator.expParser.parseVariables("<11>");
		
	}
	
	
	@Test
	public void testExpParseParenthesis() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseParenthesis("(1+2)*3=9");
		Calculator.expParser.parseParenthesis("-(1+2)*3=9");
	}
	
	@Test(expected=ExpressionParserException.class)
	public void testExpParseFunctions00() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseFunctions("[1+2]*3=9");
	}
	
	@Test(expected=FunctionNotFoundException.class)
	public void testExpParseFunctions01() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseFunctions("4+5+[1+2]*3=9");
	}
	
	@Test
	public void testExpParseFunctions02() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseFunctions("sin[30]");
		Calculator.expParser.parseFunctions("-sin[30]");
	}
	
	@Test(expected=MissingOperandException.class)
	public void testExpParseFunctions03() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseFunctions("a+b[]");
		
	}
	
	@Test(expected=ExpressionParserException.class)
	public void testExpParseFunctions04() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseFunctions("sin[1+2=3]");
		
	}
	
	@Test
	public void testExpParseOperators00() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseOperators("(1 - 2 + 3)");
	}
	
	@Test(expected=MissingOperandException.class)
	public void testExpParseOperators01() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseOperators("1 +");
	}
	
	@Test(expected=MissingOperandException.class)
	public void testExpParseOperators03() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.parseOperators("+ 1");
	}
	
	@Test
	public void testExpParseOperators02() throws Throwable{
		String exp=" a+a ";
		String numberRegex = "(([+-]?)\\d+(\\.\\d+)?([eE](-?)\\d+)?)";
		while (exp.matches("(.*)" + numberRegex + "\\s+-\\s+" + numberRegex + "(.*)")) {
			exp = exp.replaceAll(numberRegex + "\\s+-\\s+" + numberRegex, " $1 + -($6) ");
			exp = Calculator.expParser.parseParenthesis(exp);
		}
		System.out.println("ggggghhh:"+exp);
		String[] stack = exp.split("\\s+");
		System.out.println("sss_stcak:"+stack[1]+"__"+stack.length);
	}
	
	@Test(timeout=1000)
	public void testExpindexOfMatchingBracket00() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		System.out.println("VVV"+Calculator.expParser.indexOfMatchingBracket("(())(",2,'(',')'));
		Calculator.expParser.indexOfMatchingBracket("(())(",1,'(',')');

	}
	
	
	@Test(expected=UnmatchedBracketsException.class)
	public void testExpindexOfMatchingBracket01() throws Throwable{
		Calculator.expParser=new ExpressionParser(10);
		Calculator.expParser.indexOfMatchingBracket("(-4)",4,'a','b');

	}
}
