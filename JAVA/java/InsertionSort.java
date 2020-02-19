import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class InsertionSort {
  void InsertionSort(int[] nums){
  for(int i = 1; i < nums.length; i++){
    int value = nums[i];
    int j = i - 1;
    while(j >= 0 && nums[j] > value){
      nums[j + 1] = nums[j];
      j = j - 1;
    }
    nums[j + 1] = value;
  }
}

	// Method to test above
    public static void main(String args[])
    {
        InsertionSort ob = new InsertionSort();
  		int n = 1000000;
      int j = 1;
      for(j=1;j<=50;j++){
        System.out.printf(j+":;");
        //System.out.println("Enter the terms");
    		int arr[] = new int[n];
            for (int i = 0; i < n; i++)
    			arr[i] = getRandomNumberInRange(0, 65535);
            //System.out.println("Original Array:");
            //System.out.println(Arrays.toString(arr));
            long startTime = System.nanoTime();
    		ob.InsertionSort(arr);
    		long endTime = System.nanoTime();

    		// get difference of two nanoTime values
    		long timeElapsed = endTime - startTime;
    		System.out.printf("nanossegundos: " + timeElapsed + ";");

    		System.out.println("milissegundos : " +
    								timeElapsed / 1000000 + " MS");
    		//System.out.println("Sorted Array");
            //System.out.println(Arrays.toString(arr));
      }
    }

	private static int getRandomNumberInRange(int min, int max) {

		if (min >= max) {
			throw new IllegalArgumentException("max must be greater than min");
		}

		Random r = new Random();
		return r.nextInt((max - min) + 1) + min;
	}
}
