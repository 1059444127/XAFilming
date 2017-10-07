#include "XAFilmingJobComparer.h"


bool XAFilmingJobComparer::operator()(XAFilmingJobBase* left, XAFilmingJobBase* right)
{
    auto leftStatusPriority = left->GetJobStatus()->GetStatusPriority();
    auto rightStatusPriority = right->GetJobStatus()->GetStatusPriority();

    if(leftStatusPriority > rightStatusPriority) return true;
    if(leftStatusPriority < rightStatusPriority) return false;

    auto leftPriority = left->GetPriority();
    auto rightPriority = right->GetPriority();

    if(leftPriority > rightPriority) return true;
    if(leftPriority < rightPriority) return false;

    return left->GetJobID() < right->GetJobID(); // Assert Job ID Acceding, not equal
}
