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
		String output = name + "\t" + arrivalTime + "\t" + originalBurstTime + "\t" + priority + "\t"
			+ completionTime + "\t" + turnaroundTime + "\t" + waitingTime;
		return output;
	}
}


