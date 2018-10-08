int main(){

  int tomb[20];
  for(int i = 0; i < 20; i++){
    tomb[i] = i*2;
  }

  for(int i = 0; i < 20; i++){
    cout << "A tomb " << (i+1) << ". eleme: " << tomb[i] << endl;
  }

  return 0;
}
