import java.util.Arrays;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class QuickSort {

    public static void main(String[] args) {
        //int[] arr = {4, 5, 1, 2, 3, 3};

  		int n = 100000000;
      int j = 1;
  		for(j=1;j<=50;j++){
    		//System.out.println("Enter the terms");
    		int arr[] = new int[n];

        for (int i = 0; i < n; i++)
    			arr[i] = getRandomNumberInRange(0, 65535);
        System.out.printf(j+":;");
    		long startTime = System.nanoTime();
    		quickSort(arr, 0, arr.length-1);
    		long endTime = System.nanoTime();

    		// get difference of two nanoTime values
    		long timeElapsed = endTime - startTime;
    		System.out.printf("nanossegundos: " + timeElapsed + ";");

    		System.out.println("milissegundos: " +	timeElapsed / 1000000 + " MS");
          //System.out.println(Arrays.toString(arr));
      }
    }

    public static void quickSort(int[] arr, int start, int end){

        int partition = partition(arr, start, end);

        if(partition-1>start) {
            quickSort(arr, start, partition - 1);
        }
        if(partition+1<end) {
            quickSort(arr, partition + 1, end);
        }
    }

    public static int partition(int[] arr, int start, int end){
        int pivot = arr[end];

        for(int i=start; i<end; i++){
            if(arr[i]<pivot){
                int temp= arr[start];
                arr[start]=arr[i];
                arr[i]=temp;
                start++;
            }
        }

        int temp = arr[start];
        arr[start] = pivot;
        arr[end] = temp;

        return start;
    }

	private static int getRandomNumberInRange(int min, int max) {

		if (min >= max) {
			throw new IllegalArgumentException("max must be greater than min");
		}

		Random r = new Random();
		return r.nextInt((max - min) + 1) + min;
	}
}
