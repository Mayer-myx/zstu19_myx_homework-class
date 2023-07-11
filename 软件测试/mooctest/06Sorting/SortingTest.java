import static org.junit.Assert.*;

import org.junit.Test;

public class SortingTest {

    private Sorting sorting=new Sorting();
    int[] caseA={4,7,4,4,2,0};
    int[] caseB={15,16,3,2,10,12,3,6,1,5,1,2};

    @Test
    public void test() {
        //testInsertiongSort
        sorting.insertionSort(caseA);
        sorting.isSorted(caseA);

        // testQuicksort
        sorting.quicksort(caseB);

        // testSwapReferences
        Object[] ob={"123","234","345"};
        sorting.swapReferences(ob,0,2);
        // testSwap
        sorting.swap(caseA,0,2);
        sorting.isSorted(caseA);
    }

}
