/* ===== 23e2d98a0 ui.hotkey_dialog:? ===== */
/* ghidra_name=FUN_23e2d98a0 entry=23e2d98a0 size=2387 */

code * FUN_23e2d98a0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  code *pcVar9;
  char cVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong lVar14;
  code *pcVar15;
  undefined1 local_68 [16];
  longlong *local_58 [3];
  
  plVar11 = DAT_23eeb0270;
  pcVar1 = (code *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  plVar4 = (longlong *)param_3[3];
  local_58[0] = (longlong *)0x0;
  local_68 = (undefined1  [16])0x0;
  if (DAT_23eeb0270 == (longlong *)0x0) {
LAB_23e2d9902:
    DAT_23eeb0270 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0260,DAT_23eeb0268,0x28);
  }
  else {
    lVar14 = *DAT_23eeb0270;
    if (1 < lVar14) {
      *DAT_23eeb0270 = lVar14 + -1;
      goto LAB_23e2d9902;
    }
    if (DAT_23eeb0270[2] != 0) {
      *DAT_23eeb0270 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e2d9902;
    }
  }
  plVar6 = DAT_23eeb0270;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar11 = DAT_23eeb0270 + 9;
  lVar5 = *(longlong *)(lVar14 + 8);
  DAT_23eeb0270[0xf] = lVar5;
  *(longlong **)(lVar14 + 8) = plVar11;
  if ((lVar5 != 0) &&
     (((*(char *)(lVar5 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar5 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar5 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar5 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar5 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  pcVar9 = _Py_NoneStruct_exref;
  lVar14 = *(longlong *)(*(longlong *)(param_2 + 0xd8) + 0x10);
  if (lVar14 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar14 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar14 = DAT_23ed6cd40 + 0x30;
    }
    local_68._8_8_ =
         PyUnicode_FromFormat
                   ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                    ,lVar14);
    local_68._0_8_ = *(undefined8 *)PyExc_NameError_exref;
    *(longlong *)local_68._0_8_ = *(longlong *)local_68._0_8_ + 1;
    local_58[0] = (longlong *)0x0;
    if ((code *)local_68._0_8_ != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,local_68,local_68 + 8,local_58);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_68._8_8_);
    uVar13 = 0xf;
    plVar12 = DAT_23ed6a4f8;
    plVar11 = local_58[0];
  }
  else {
    pcVar15 = (code *)0x0;
    if (pcVar1 != _Py_NoneStruct_exref) {
      pcVar15 = pcVar1;
    }
    plVar11 = (longlong *)FUN_23e9543b0(param_1,DAT_23eead8e0,lVar14,pcVar15);
    if (plVar11 != (longlong *)0x0) {
      *(undefined4 *)(plVar6 + 5) = 0xf;
      plVar12 = (longlong *)FUN_23e915840(param_1,plVar11,DAT_23ed6cdb0,plVar3);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar12 != (longlong *)0x0) {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        cVar10 = FUN_23e8d9ac0(pcVar1,DAT_23eead3e0,plVar2);
        if (cVar10 == '\0') {
          plVar11 = *(longlong **)(param_1 + 0x70);
          local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
          uVar13 = 0x10;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar12 = DAT_23ed6a4f8;
        }
        else {
          cVar10 = FUN_23e8d9ac0(pcVar1,DAT_23eead3e8,DAT_23ed6cd28);
          if (cVar10 == '\0') {
            local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar11 = *(longlong **)(param_1 + 0x70);
            uVar13 = 0x11;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = DAT_23ed6a4f8;
          }
          else {
            plVar11 = (longlong *)PySet_New(0);
            cVar10 = FUN_23e8d9ac0(pcVar1,DAT_23eead3f0,plVar11);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (cVar10 == '\0') {
              local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plVar11 = *(longlong **)(param_1 + 0x70);
              uVar13 = 0x12;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar12 = DAT_23ed6a4f8;
            }
            else {
              cVar10 = FUN_23e8d9ac0(pcVar1,DAT_23eead3f8,pcVar9);
              uVar8 = DAT_23eead400;
              if (cVar10 == '\0') {
                local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
                local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plVar11 = *(longlong **)(param_1 + 0x70);
                uVar13 = 0x13;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar12 = DAT_23ed6a4f8;
              }
              else {
                *(undefined4 *)(plVar6 + 5) = 0x15;
                plVar11 = (longlong *)FUN_23e915840(param_1,pcVar1,uVar8,plVar4);
                if (plVar11 == (longlong *)0x0) {
                  local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  plVar11 = *(longlong **)(param_1 + 0x70);
                  uVar13 = 0x15;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar12 = DAT_23ed6a4f8;
                }
                else {
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  lVar14 = DAT_23eead410;
                  uVar8 = DAT_23eead408;
                  *(undefined4 *)(plVar6 + 5) = 0x16;
                  plVar11 = (longlong *)
                            FUN_23e915840(param_1,pcVar1,uVar8,*(undefined8 *)(lVar14 + 0x18));
                  if (plVar11 == (longlong *)0x0) {
                    local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plVar11 = *(longlong **)(param_1 + 0x70);
                    uVar13 = 0x16;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar12 = DAT_23ed6a4f8;
                  }
                  else {
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    lVar14 = DAT_23eead420;
                    uVar8 = DAT_23eead418;
                    *(undefined4 *)(plVar6 + 5) = 0x17;
                    plVar11 = (longlong *)FUN_23e954670(param_1,pcVar1,uVar8,lVar14 + 0x18);
                    if (plVar11 == (longlong *)0x0) {
                      local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      plVar11 = *(longlong **)(param_1 + 0x70);
                      uVar13 = 0x17;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar12 = DAT_23ed6a4f8;
                    }
                    else {
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      *(undefined4 *)(plVar6 + 5) = 0x18;
                      plVar11 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eead428);
                      if (plVar11 == (longlong *)0x0) {
                        local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        plVar11 = *(longlong **)(param_1 + 0x70);
                        uVar13 = 0x18;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar12 = DAT_23ed6a4f8;
                      }
                      else {
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        *(undefined4 *)(plVar6 + 5) = 0x19;
                        plVar11 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eead430);
                        if (plVar11 != (longlong *)0x0) {
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                          plVar11 = *(longlong **)(lVar14 + 0x28);
                          plVar6 = (longlong *)plVar11[2];
                          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                               *(undefined8 *)(lVar14 + 0x30);
                          *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                          if (plVar6 != (longlong *)0x0) {
                            plVar11[2] = 0;
                            *plVar6 = *plVar6 + -1;
                            if (*plVar6 == 0) {
                              (**(code **)(plVar6[1] + 0x30))();
                            }
                          }
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                          plVar11[0xf] = 0;
                          *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
                          if (*(longlong *)pcVar1 == 0) {
                            (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
                          }
                          *plVar2 = *plVar2 + -1;
                          if (*plVar2 == 0) {
                            (**(code **)(plVar2[1] + 0x30))(plVar2);
                          }
                          *plVar3 = *plVar3 + -1;
                          if (*plVar3 == 0) {
                            (**(code **)(plVar3[1] + 0x30))(plVar3);
                          }
                          *plVar4 = *plVar4 + -1;
                          if (*plVar4 != 0) {
                            return pcVar9;
                          }
                          (**(code **)(plVar4[1] + 0x30))(plVar4);
                          return pcVar9;
                        }
                        local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        plVar11 = *(longlong **)(param_1 + 0x70);
                        uVar13 = 0x19;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar12 = DAT_23ed6a4f8;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto joined_r0x00023e2d9ccb;
      }
    }
    local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar11 = *(longlong **)(param_1 + 0x70);
    uVar13 = 0xf;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = DAT_23ed6a4f8;
  }
joined_r0x00023e2d9ccb:
  DAT_23ed6a4f8 = plVar12;
  local_58[0] = plVar11;
  if (plVar11 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar14 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar5 = plVar12[-1];
    puVar7 = *(undefined8 **)(lVar14 + 8);
    *puVar7 = plVar12 + -2;
    plVar12[-2] = lVar14;
    plVar12[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar14 + 8) = plVar12 + -2;
    plVar11 = plVar12;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))(local_58[0]);
    }
  }
  else if ((longlong *)plVar11[3] != plVar6) {
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar14 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
    lVar5 = plVar12[-1];
    puVar7 = *(undefined8 **)(lVar14 + 8);
    *puVar7 = plVar12 + -2;
    plVar12[-2] = lVar14;
    plVar12[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar14 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar11;
    *plVar11 = *plVar11 + 1;
    plVar11 = plVar12;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))();
    }
  }
  local_58[0] = plVar11;
  FUN_23e8bba40(plVar6,"ooooc",pcVar1,plVar2,plVar3,plVar4,*(undefined8 *)(param_2 + 0xd8));
  if (DAT_23eeb0270 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    DAT_23eeb0270 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar14 + 0x28);
  plVar6 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar6 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
  if (*(longlong *)pcVar1 == 0) {
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,local_68._0_8_,local_68._8_8_,local_58[0]);
  return (code *)0x0;
}
