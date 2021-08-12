package com.eclipse_java.contect;

import java.util.Scanner;

public class HelloWorld
{
	/**
	 * @author liu
	 * @time 2021/8/12
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		System.out.println("请输入一个数字，将会得到一个回形矩阵");
		//数组创建
		int input=scan.nextInt();
		int[][] squareArr=new int[input][input];
		int value=1;
		int row=0;
		int lin=0;
		int m=input;
		for(int i=0;i<input*input;i++) {
			if(row==0&&lin==0) {
				for(int j=0;j<m;j++) {
					squareArr[row][lin++]=value++;
				}
				lin--;
			}
			else {
				for(int j=0;j<m;j++) {
					squareArr[row][++lin]=value++;
				}
			}
			for(int j=0;j<m-1;j++) {
				squareArr[++row][lin]=value++;
			}
			for(int j=0;j<m-1;j++) {
				squareArr[row][--lin]=value++;
			}
			for(int j=0;j<m-2;j++) {
				squareArr[--row][lin]=value++;
			}
			m-=2;
		}
		for(int i=0;i<input;i++) {
			for(int j=0;j<input;j++) {
				System.out.print(squareArr[i][j]+"\t");
			}
			System.out.println();
			System.out.println();
		}
		
	}
} 
