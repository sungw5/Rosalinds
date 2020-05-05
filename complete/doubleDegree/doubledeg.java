package Rosalind_java;

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;


public class doubledeg {
	
	/********* I used java code to learn how to get file IO in Java  *************/
	
	
	public static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
		// connect edges in undirected graph
		adj.get(u).add(v);
		adj.get(v).add(u);
	}

	public static void main(String[] args) throws FileNotFoundException {
		int i,j;
		int deg, n, m;
		int u,v;
		
		// create adjacency list
		ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
		
		// create file input
		File file = new File("rosalind_doubledeg.txt");
		Scanner inputP = new Scanner(file);
		
		// get # of vertices and # of edges
		n = inputP.nextInt();
		m = inputP.nextInt();

		for(i=0; i<=n; i++) {
			ArrayList<Integer> lst = new ArrayList<Integer>();
			adj.add(lst);
		}
		
		while(inputP.hasNext()) {
			// get input values
			u = inputP.nextInt();
			v = inputP.nextInt();
			addEdge(adj, u, v);
		}
		inputP.close();
		
		
		for(i=1; i<=n; i++) {
			deg = 0;
			
			for(j=0; j<adj.get(i).size(); j++) {
				deg += adj.get(adj.get(i).get(j)).size();
			}
			// print out the sum of neighbor's degrees
			System.out.print(deg + " ");
		}
		
		
	}

}
