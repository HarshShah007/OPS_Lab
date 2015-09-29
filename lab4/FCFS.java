import java.util.*;
import javax.swing.*;
import java.io.*;

public class FCFS {

	static ArrayList< Process > database = new ArrayList< Process >();

	public static void main(String[] args) {

		System.out.println("FCFS Scheduling Alogrithm");
		String fileName = getInput("Enter file name: ");
		getFromFile(fileName);

		/*Algorithm starts here*/
		ArrayList< Process > ganttChart = new ArrayList< Process >();
		Queue< Process > queue = new LinkedList< Process >();

		int timer = 0;
		while (true) {
			for (Process process : database) {
				if (process.arrivalTime == timer) {
					queue.add(process);
				}
			}
			if (queue.peek() == null) {
				ganttChart.add(null);
			} else {
				ganttChart.add(queue.peek());
				queue.peek().burstTime -= 1;
				if (queue.peek().burstTime == 0) {
					queue.peek().completionTime = timer + 1;
					queue.remove();
				}
			}
			timer += 1;
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
		while (counter < ganttChart.size()) {
			Process current = ganttChart.get(counter);
			if (current != prev) {
				if (prev != null) {
					System.out.println(prev.name + " " + counter);
				} else {
					System.out.println("Idle " + counter);
				}
			}
			counter += 1;
			prev = current;							
		}
		if (prev != null) {
			System.out.println(prev.name + " " + counter);
		} else {
			System.out.println("Idle " + counter);
		}

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

