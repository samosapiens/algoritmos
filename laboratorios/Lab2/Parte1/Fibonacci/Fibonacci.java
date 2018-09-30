package algoritmos_lab1;

public class Fibonacci {

	public static double phi1 = (1.0 + Math.sqrt(5.0))/2.0;
	public static double phi2 = (1.0 - Math.sqrt(5.0))/2.0;

	public static long fiboLinear(int n) {
		int i;
		long fibo0, fibo1, fibo;
		if(n == 0) 			
			return 0;
		else if(n == 1) 	
			return 1;
		fibo = 0;
		fibo0 = 0; 
		fibo1 = 1; 
		for(i=1; i<n; i++) {
			fibo = fibo0 + fibo1; 
			fibo0 = fibo1; 
			fibo1 = fibo;
		}
		return fibo;
	}

	public static long fiboRecursive(int n) {
		if(n<2) return (long) n;
		else  	return fiboRecursive(n-1) + fiboRecursive(n-2);
			
	}

	public static long fiboAnalythic(int n) {
		return (long) ((long) (Math.pow(phi1, n) - Math.pow(phi2, n))/Math.sqrt(5.0));
	}

	public static void testByte() {
		int n=0;
		byte fibo_test=0;
		long t0, t1, fibo_real=0;
		// Test lineal:
		t0 = System.nanoTime();
		while(fibo_real >= 0 && fibo_real < Math.pow(2, 7)) {
			fibo_real = fiboLinear(n);
			fibo_test = (byte) fiboLinear(n);
			//System.out.println("\t- n: " + n + ", real: " + fibo_real + ", test: " + fibo_test);
			n++;
		}
		t1 = System.nanoTime();
		System.out.println("- Overflow Bytes Fibonacci: (N = " + (n-1) + ", t=" + (t1 - t0) + " ns, avg=" + (t1 - t0)/((double) n) + " ns)");
	}

	public static void testShort() {
		int n=0;
		short fibo_test=0;
		long t0, t1, fibo_real=0;
		// Test lineal:
		t0 = System.nanoTime();
		while(fibo_real >= 0 && fibo_real < Math.pow(2, 15)) {
			fibo_real = fiboLinear(n);
			fibo_test = (short) fiboLinear(n);
			//System.out.println("\t- n: " + n + ", real: " + fibo_real + ", test: " + fibo_test);
			n++;
		}
		t1 = System.nanoTime();
		System.out.println("- Overflow Short Integer Fibonacci: (N = " + (n-1) + ", t=" + (t1 - t0) + " ns, avg=" + (t1 - t0)/((double) n) + " ns)");
	}

	public static void testInt() {
		int n=0;
		int fibo_test=0;
		long t0, t1, fibo_real=0;
		// Test lineal:
		t0 = System.nanoTime();
		while(fibo_real >= 0 && fibo_real < Math.pow(2, 31)) {
			fibo_real = fiboLinear(n);
			fibo_test = (int) fiboLinear(n);
			//System.out.println("\t- n: " + n + ", real: " + fibo_real + ", test: " + fibo_test);
			n++;
		}
		t1 = System.nanoTime();
		System.out.println("- Overflow Integer Fibonacci: (N = " + (n-1) + ", t=" + (t1 - t0) + " ns, avg=" + (t1 - t0)/((double) n) + " ns)");
	}

	public static void testLong() {
		int n=0;
		long t0, t1, fibo_real=0, fibo_test=0;
		// Test lineal:
		t0 = System.nanoTime();
		while(fibo_real >= 0 && fibo_real < Math.pow(2, 63)) {
			fibo_real = fiboLinear(n);
			fibo_test = fiboLinear(n);
			//System.out.println("\t- n: " + n + ", real: " + fibo_real + ", test: " + fibo_test);
			n++;
		}
		t1 = System.nanoTime();
		System.out.println("- Overflow Long Fibonacci: (N = " + (n-1) + ", t=" + (t1 - t0) + " ns, avg=" + (t1 - t0)/((double) n) + " ns)");
	}
	
	public static void main(String[] args) {
		// Test Byte
		testByte();
		// Test Short
		testShort();
		// Test int
		testInt();
		// Test long
		testLong();
	}

}

