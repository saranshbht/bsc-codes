//Question 14,15

import java.util.Scanner;

class MaxThread extends Thread {
    private int lo, hi;
    private int[] arr;
    private int max;
    
    public MaxThread(int[] arr, int lo, int hi) {
        this.lo = lo;
        this.hi = hi;
        this.arr = arr;
    }
    
    
    public void run() {
        for(int i = lo; i < hi; i++){
            if(i==lo)
				max=arr[i];
			else{
				if(max<arr[i])
					max=arr[i];
			}
        }
    }
    
    /*
     * Sum the elements of an array.
     * 
     * parameter arr array to sum
     * return sum of the array's elements
     * throws InterruptedException shouldn't happen
     */
    public static int maxVal(int[] arr) throws InterruptedException {
        int len = arr.length;
        int max = 0;
        
        // Create and start 4 threads.
        MaxThread[] tm = new MaxThread[4];
        for (int i = 0; i < 4; i++) {
            tm[i] = new MaxThread(arr, (i * len) / 4, ((i + 1) * len / 4));
            tm[i].start();
        }
        
        // Wait for the threads to finish and sum their results.
        for (int i = 0; i < 4; i++) {
            tm[i].join();
            if(i==0)
				max=tm[i].max;
			else{
				if(max<tm[i].max)
					max=tm[i].max;
			}
        }
        return max;
    }
}

class MaxValue{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter the size of the array: ");
		int n=sc.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter array elements: ");
		for(int i=0;i<n;i++)
			arr[i]=sc.nextInt();
		try{
		System.out.println("Maximum Value: "+MaxThread.maxVal(arr));
		}
		catch(Exception e){}
	}
}