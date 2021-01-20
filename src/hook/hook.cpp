#include "hook.h"

#include <MinHook.h>

namespace stuff {
  namespace hook {
    void init() {
      MH_Initialize();
    }

    void queue(LPVOID pTarget, LPVOID pDetour, LPVOID* ppOriginal) {
      MH_CreateHook((LPVOID)pTarget, pDetour, ppOriginal);
      MH_QueueEnableHook((LPVOID)pTarget);
    }
    void apply() {
      MH_ApplyQueued();
    }

    void unhook(std::vector<intptr_t>& targets) {
      MH_Initialize();
      for (auto& target : targets) {
        MH_QueueDisableHook((LPVOID)target);
      }
      MH_ApplyQueued();
    }
  }  // namespace hook
}  // namespace stuff
