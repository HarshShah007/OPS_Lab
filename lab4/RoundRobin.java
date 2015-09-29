import java.util.*;
import javax.swing.*;
import java.io.*;

public class RoundRobin {

	static ArrayList< Process > database = new ArrayList< Process >();

	public static void main(String[] args) {

		System.out.println("FCFS Scheduling Alogrithm");
		String fileName = getInput("Enter file name: ");
		int timeQuantum = Integer.parseInt(getInput("Enter time quantum: "));
		getFromFile(fileName);

		/*Algorithm starts here*/
		ArrayList< Process > ganttChart = new ArrayList< Process >();
		Queue< Process > queue = new LinkedList< Process >();

		int timer = 0;
		int counter = 0;
		while (true) {
			for (Process process : database) {
				if (process.arrivalTime == timer) {
					queue.add(process);
				}
			}
			if (queue.peek() == null) {
				ganttChart.add(null);
				timer += 1;
				counter = 0;
			} else {
				ganttChart.add(queue.peek());
				queue.peek().burstTime -= 1;
				timer += 1;
				counter += 1;

				if (queue.peek().burstTime == 0) {
					queue.peek().completionTime = timer;
					queue.remove();
					counter = 0;
				} else if (counter == timeQuantum) {
					counter = 0;
					queue.add(queue.peek());
					queue.remove();
				}
			}

			if (isAllCompleted()) {
				break;
			}
		}

		for (Process process : database) {
			process.turnaroundTime = process.completionTime - process.arrivalTime;
			process.waitingTime = process.turnaroundTime - process.originalBurstTime;
		}

		System.out.println("Name\tAT\tBT\tPriority CT\tTAT\tWT");
		for (Process process : database) {
			System.out.println(process);
		}

		printGanttChart(ganttChart);

	}
	public static void printGanttChart(ArrayList<Process> ganttChart) {

		/*Gantt Chart starts here*/
		System.out.println("\nGANTT CHART\n");
		int counter = 1;
		Process prev = ganttChart.get(0);
		String out1 = "";
		String out2 = "";
		while (counter < ganttChart.size()) {
			Process current = ganttChart.get(counter);
			out1 += "-";
			out2 += " ";
			if (current != prev) {
				if (prev != null) {
					out1 += "       ";
					out2 += "|";
					out2 += (prev.name + " " + counter);
					out2 += "|";
				} else {
					out1 += "       ";
					out2 += "|";
					out2 += ("Idle " + counter);
					out2 += "|";
				}
			}
			counter += 1;
			prev = current;							
		}
		if (prev != null) {
			out2 += "|";
			out2 += (prev.name + " " + counter);
		} else {
			out2 += "|";
			out2 += ("Idle " + counter);
		}
		System.out.println(out1);
		System.out.println(out2);
		System.out.println(out1);
	}

	public static boolean isAllCompleted() {
		/*Check if all process have been completed */
		for (Process process : database) {
			if (process.burstTime != 0) {
				return false;
			}
		}
		return true;
	}

	public static void getFromFile(String fileName) {

		try {
			BufferedReader br = new BufferedReader(new FileReader(fileName));

			String input = br.readLine();
			while (input != null) { 
				database.add(parseLine(input));
				input = br.readLine();
			}
		} catch (IOException iex) { ; }
	}

	public static Process parseLine(String name) {
		Process process = new Process();
		String[] split = name.split(" ");
		process.name = split[0];
		process.arrivalTime = Integer.parseInt(split[1]);
		process.burstTime = Integer.parseInt(split[2]);
		process.originalBurstTime = process.burstTime;
		process.priority = Integer.parseInt(split[3]);
		return process;
	}

	public static String getInput(String prompt) {
		System.out.print(prompt);
		String input = null;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			input = br.readLine();
		} catch (IOException iex) { ; }
		return input;
	}
}
