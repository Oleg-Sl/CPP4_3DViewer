#ifndef _3DVIEWER_CONTROLLER_INCLUDE_OPERATIONRESULT_H_
#define _3DVIEWER_CONTROLLER_INCLUDE_OPERATIONRESULT_H_

#include <string>

struct OperationResult {
  OperationResult(std::string error_message, bool is_success)
      : error_message(error_message), is_success(is_success) {}

  std::string error_message;
  bool is_success;
};

#endif  // _3DVIEWER_CONTROLLER_INCLUDE_OPERATIONRESULT_H_