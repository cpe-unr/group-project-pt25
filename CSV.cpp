  OUTPUT = OUTPUT + ".csv";
  std::ofstream myFile(OUTPUT);

  // Send data to the stream
  myFile << ",Artist,Track,Album,Data,Genre,Track Number,Comments,";
  myFile << "\n";
  myFile << fileInfo1;
  myFile << "\n";
  myFile << fileInfo2;
  myFile << "\n";
  myFile << fileInfo3;
  myFile << "\n";
  myFile << fileInfo4;

  // Close the file
  myFile.close();
