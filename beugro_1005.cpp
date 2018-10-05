int main(){
  int tomb[20];

  for(int i = 0; i < 20; i++){
    tomb[i] = (i*2)+1;
  }

  for(int i = 0; i < 20; i++){
    cout << "tomb " << i << " -> " << tomb[i];
  }

  return 0;
}
