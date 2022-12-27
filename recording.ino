void startRecording() {
  //  pump 1
  if (p1_prevPos != counter1) {
    p1_memory[p1_index] = counter1;
    seq_pointer[seq_index] = 1000 + p1_index;
    p1_index++;
    seq_index++;
  }
  p1_prevPos = counter1;
}
