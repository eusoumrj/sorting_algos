import java.util.Arrays;
import java.util.Scanner;
import java.util.Random;
import java.util.concurrent.TimeUnit;

class MergeSort {
	private static Scanner sc;

	public static void main(String args[]) {
		int n = 10000;
		int j = 1;
		for(j=1;j<=50;j++){
			System.out.printf(j+":;");
			int arr[] = new int[n];
			for (int i = 0; i < n; i++)
			arr[i] = getRandomNumberInRange(0, 65535);
			//System.out.println("The unsorted array is:");
			//System.out.println(Arrays.toString(arr));
			long startTime = System.nanoTime();
			mergesort(arr);
			long endTime = System.nanoTime();

			// get difference of two nanoTime values
			long timeElapsed = endTime - startTime;
			System.out.printf("Nanossegundos: " + timeElapsed + ";");

			System.out.println("Milissegundos : " +
								timeElapsed / 1000000 + " MS");
			//System.out.println("The sorted array is:");
			//System.out.println(Arrays.toString(arr));
		}
	}

	static void mergesort(int arr[]) {
		int n = arr.length;
		if (n < 2)
			return;
		int mid = n / 2;
		int left[] = new int[mid];
		int right[] = new int[n - mid];
		for (int i = 0; i < mid; i++)
			left[i] = arr[i];
		for (int i = mid; i < n; i++)
			right[i - mid] = arr[i];
		mergesort(left);
		mergesort(right);
		merge(arr, left, right);
	}

	public static void merge(int arr[], int left[], int right[]) {
		int nL = left.length;
		int nR = right.length;
		int i = 0, j = 0, k = 0;
		while (i < nL && j < nR) {
			if (left[i] <= right[j]) {
				arr[k] = left[i];
				i++;
			} else {
				arr[k] = right[i];
				j++;
			}
			k++;
		}
		while (i < nL) {
			arr[k] = left[i];
			i++;
			k++;
		}
		while (j < nR) {
			arr[k] = right[j];
			j++;
			k++;
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
