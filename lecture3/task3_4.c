int CopyRead(int (*PointerReadQueue)(int*),int *copy_element)
{
     return PointerReadQueue(copy_element);
}
