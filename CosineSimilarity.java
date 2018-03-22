package com.vivo.ai.service.process;

import java.util.Random;

class CosineSimilarity {
	static {
		try {
			System.load("/home/liyongqiang/lib/libcosim.so");
		} catch (Exception ex) {
			System.err.println("Native code library failed to load.\n" + ex);
			System.exit(1);
		}
	}

	public static void main(String argv[]) {
		Random rnd = new Random(123);
		final int size = 300;
		float[] A = new float[size];
		float[] B = new float[size];
		for(int i=0;i<size;i++){
			A[i] = rnd.nextFloat();
			B[i] = rnd.nextFloat();
		}
		float cosim = dd(dot(A,A), A, B);
		System.out.println(cosim);
		cosim = dd( A, B);
		System.out.println(cosim);
	}

	public static float dot(float[] A, float[] B) {
		int len = A.length;
		float sum = 0.0f;
		for(int i=0;i<len;i++){
			sum += A[i] * B[i];
		}
		return sum;
	}

	public static native float dd(final float[] A, final float[] B);

	public static native float dd(final float a2, final float[] A, final float[] B);
}
