/**
 * 
 */
package net.mooctest;

import org.hamcrest.CoreMatchers;
import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.assertThat;

public class NextdayTest {

    // 有效
    @Test
    public void testDate01() {
        Date date, result, expected;
        date = new Date(2, 29, 2016);
        result = Nextday.nextDay(date);
        result.printDate();
        expected = new Date(3, 1, 2016);
        Assert.assertEquals(result, expected);

        date = new Date(1, 28, 2017);
        result = Nextday.nextDay(date);
        result.printDate();
        expected = new Date(1, 29, 2017);
        Assert.assertEquals(result, expected);

        date = new Date(1, 31, 2017);
        result = Nextday.nextDay(date);
        result.printDate();
        expected = new Date(2, 1, 2017);
        Assert.assertEquals(result, expected);

        date = new Date(4, 30, 2017);
        result = Nextday.nextDay(date);
        result.printDate();
        expected = new Date(5, 1, 2017);
        Assert.assertEquals(result, expected);

        date = new Date(12, 31, 2017);
        result = Nextday.nextDay(date);
        result.printDate();
        expected = new Date(1, 1, 2018);
        Assert.assertEquals(result, expected);

        date = new Date(12, 31, -1);
        result = Nextday.nextDay(date);
        result.printDate();
        expected = new Date(1, 1, 1);
        Assert.assertEquals(result, expected);


        // fixed 方法覆盖
        String s = date.toString();

        // fixed 代码行覆盖
        boolean b = date.equals(null);
        Year year = new Year(2021);
        b = year.equals(null);
        Month month = new Month(5, year);
        b = month.equals(null);
        Day day = new Day(21, month);
        b = day.equals(null);

    }

    // 抛出异常
    @Test
    public void testDate02() {
        Object[][] exp = {
                {31, 12, -1, "Not a valid month"},
                {3, 1, 0, "Not a valid month"},
                {-1, 1, 1901, "Not a valid month"},
                {-1, 1, 1901, "Not a valid month"},
                {13, 1, 1901, "Not a valid month"},
                {1, -1, 1901, "Not a valid day"},
                {2, 30, 2016, "Not a valid day"},
                {2, 29, 2017, "Not a valid day"},
                {3, 32, 2017, "Not a valid day"},
                {4, 31, 2017, "Not a valid day"},
                {4, 32, 2017, "Not a valid day"}
        };
        for (Object[] e : exp) {
            try {
                Date date = new Date((int) e[0], (int) e[1], (int) e[2]);
                Date d = Nextday.nextDay(date);
            } catch (IllegalArgumentException ex) {
                assertThat(ex.getMessage(), CoreMatchers.containsString((String) e[3]));
            }
        }
    }
}

