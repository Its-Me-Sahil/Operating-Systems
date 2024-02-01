  cout<<"Enter the total number of references string";
    cin>>n;
    cout<<"Enter the total no fram ";
    cin>>fs;
    cout<<"enter the pages";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
   }
   for(int i=0;i<fs;i++)
   {
    frames[i] =0;
   }
   cout<<"pages \t\tframes";
   for(int i=0;i<n;i++)
   {
        available=0;
        cout<<pages[i]<<"\t\t";