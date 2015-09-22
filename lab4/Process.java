public class Process {

	String name;
	int arrivalTime;
	int burstTime;
	int priority;
	int completionTime;
	int turnaroundTime;
	int waitingTime;

	int originalBurstTime;

	@Override
	public String toString() {
		String output = name + " " + arrivalTime + " " + originalBurstTime + " " + priority + " "
			+ completionTime + " " + turnaroundTime + " " + waitingTime;
		return output;
	}
}

