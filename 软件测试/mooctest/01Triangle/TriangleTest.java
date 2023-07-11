package net.mooctest;
import static org.junit.Assert.*;

import org.junit.Test;


public class TriangleTest {
	
	Triangle T1 = new Triangle(2,3,4);
	Triangle T4 = new Triangle(0,1,2);
	Triangle T7 = new Triangle(Long.MAX_VALUE,2,4);
	Triangle T10 = new Triangle(3,3,3);
	Triangle T11= new Triangle(3,4,4);
	
	long []borders= {0,0,0}; 
	@Test
	public void testTriangle() {
		assertEquals(true, T1.isTriangle(T1));
		assertEquals(false,T4.isTriangle(T4));
		assertFalse(T7.isTriangle(T7));
		assertTrue(T10.isTriangle(T10));
		assertTrue(T11.isTriangle(T11));
	}

	@Test
	public void testGetType() {
		assertTrue("Illegal"==T4.getType(T4));	
		assertTrue("Regular"==T10.getType(T10));
		assertTrue("Isosceles"==T11.getType(T11));
		assertTrue("Scalene"==T1.getType(T1));
	}

	@Test
	public void testDiffOfBorders() {
		assertTrue(1==T1.diffOfBorders(T1.lborderA, T1.lborderB));
	}

	@Test
	public void testGetBorders() {
		borders=T1.getBorders();
		assertTrue(T1.lborderA==borders[0]);
		assertEquals(T1.lborderB,borders[1]);
		assertEquals(T1.lborderC,borders[2]);
	}
	
}
