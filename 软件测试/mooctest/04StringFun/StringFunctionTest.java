package net.mooctest;


import org.junit.Test;

import static org.junit.Assert.*;

public class StringFunctionTest {

	@Test(timeout = 4000)
    public void test1() {
		
		boolean hw1 = StringFunction.isPalindromeInPlace("abcba");
        assertTrue(hw1);
        boolean hw2 = StringFunction.isPalindromeInPlace("abcd");
        assertFalse(hw2);
        
        String[] strings = StringFunction.generateSubsets("ab");
        assertArrayEquals(new String[]{"", "b", "a", "ba" }, strings);

        int i = StringFunction.levenshteinDistanceIterative("abc", "a");
        assertEquals(2, i);
        
        int j = StringFunction.levenshteinDistanceRecursive("abc", "a");
        assertEquals(2, j);

        String s1 = StringFunction.reverseWordsInPlace("");
        assertEquals("", s1);

        String s2 = StringFunction.reverseWordsInPlace("abc");
        assertEquals("abc", s2);

        String s3 = StringFunction.reverseWordsInPlace("abc  de");
        assertEquals("de  abc", s3);

        String s4 = StringFunction.reverseWordsInPlace("abc  de fgh");
        assertEquals("fgh de  abc", s4);

        String s5 = StringFunction.reverseWordsByCharWithAdditionalStorage("abc  123");
        assertEquals("123  abc", s5);

        String s6 = StringFunction.reverseWordsByCharWithAdditionalStorage("abc  123 de");
        assertEquals("de 123  abc", s6);

    }

    
	@Test(timeout = 4000)
    public void test2() {
        Manacher.getLongestPalindromicSubstring(null);
        Manacher.getLongestPalindromicSubstring("");
        Manacher.getLongestPalindromicSubstring("abcde");
        Manacher.getLongestPalindromicSubstring("abc de");
        Manacher.getLongestPalindromicSubstring("abcdef");
        Manacher.getLongestPalindromicSubstring("abadeed");
    }
}
