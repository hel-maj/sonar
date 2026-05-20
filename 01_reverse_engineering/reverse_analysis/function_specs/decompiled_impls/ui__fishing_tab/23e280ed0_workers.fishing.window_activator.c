/* ===== 23e280ed0 ui.fishing_tab:c1139 ===== */
/* ghidra_name=FUN_23e280ed0 entry=23e280ed0 size=2036 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e280ed0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined8 uVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  code *pcVar12;
  undefined4 uVar13;
  undefined1 local_68 [16];
  longlong *local_58 [3];
  
  plVar10 = _DAT_23eeb05f8;
  plVar1 = (longlong *)*param_3;
  local_58[0] = (longlong *)0x0;
  local_68 = (undefined1  [16])0x0;
  if (_DAT_23eeb05f8 == (longlong *)0x0) {
LAB_23e280f1c:
    _DAT_23eeb05f8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0638,DAT_23eeb0600,8);
  }
  else {
    lVar2 = *_DAT_23eeb05f8;
    if (1 < lVar2) {
      *_DAT_23eeb05f8 = lVar2 + -1;
      goto LAB_23e280f1c;
    }
    if (_DAT_23eeb05f8[2] != 0) {
      *_DAT_23eeb05f8 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e280f1c;
    }
  }
  plVar7 = _DAT_23eeb05f8;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeb05f8 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb05f8[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  uVar8 = _DAT_23eeae840;
  *(undefined4 *)(plVar7 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar8);
  if (plVar10 != (longlong *)0x0) {
    *(undefined4 *)(plVar7 + 5) = 0x3b;
    plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eeae848);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar1 == (longlong *)0x0) {
        local_68._8_8_ =
             PyUnicode_FromFormat
                       ("cannot access local variable \'%U\' where it is not associated with a value"
                        ,_DAT_23eeae850);
        local_68._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
        *(longlong *)local_68._0_8_ = *(longlong *)local_68._0_8_ + 1;
        local_58[0] = (longlong *)0x0;
        if ((code *)local_68._0_8_ != _Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,local_68,local_68 + 8,local_58);
        }
        uVar13 = 0x3d;
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_68._8_8_);
        plVar11 = DAT_23ed6a4f8;
        plVar10 = local_58[0];
      }
      else {
LAB_23e281020:
        do {
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeae840);
          if (plVar10 == (longlong *)0x0) {
LAB_23e281508:
            pcVar12 = *(code **)(param_1 + 0x60);
            local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e28117e;
          }
          plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23eeae858);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 == (longlong *)0x0) goto LAB_23e281508;
          iVar9 = FUN_23a35f020(plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          lVar2 = _DAT_23eeae868;
          if (iVar9 == -1) goto LAB_23e281508;
          if (iVar9 == 0) {
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeae870);
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar7 + 5) = 0x3f;
              plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eeae878);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar10 = *(longlong **)(lVar2 + 0x28);
                plVar7 = (longlong *)plVar10[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
                *(undefined4 *)(plVar10 + 8) = 0xffffffff;
                if (plVar7 != (longlong *)0x0) {
                  plVar10[2] = 0;
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    (**(code **)(plVar7[1] + 0x30))();
                  }
                }
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                plVar10[0xf] = 0;
                pcVar12 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar1 = *plVar1 + -1;
                if (*plVar1 != 0) {
                  return pcVar12;
                }
                (**(code **)(plVar1[1] + 0x30))(plVar1);
                return pcVar12;
              }
            }
            local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar10 = *(longlong **)(param_1 + 0x70);
            uVar13 = 0x3f;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar11 = DAT_23ed6a4f8;
            goto joined_r0x00023e2811a5;
          }
          *(undefined4 *)(plVar7 + 5) = 0x3e;
          plVar10 = (longlong *)
                    FUN_23e915840(param_1,plVar1,_DAT_23eeae860,*(undefined8 *)(lVar2 + 0x18));
          if (plVar10 == (longlong *)0x0) {
            local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar10 = *(longlong **)(param_1 + 0x70);
            uVar13 = 0x3e;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar11 = DAT_23ed6a4f8;
            goto joined_r0x00023e2811a5;
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          lVar2 = *(longlong *)(param_1 + 0x10);
          if (((*(int *)(*(longlong *)(lVar2 + 0x28) + 0x160) != 0) || (*(int *)(lVar2 + 0x78) != 0)
              ) && ((iVar9 = Py_MakePendingCalls(), iVar9 < 0 &&
                    (pcVar12 = *(code **)(param_1 + 0x60), pcVar12 != (code *)0x0))))
          goto LAB_23e281175;
          if (*(int *)(lVar2 + 0x68) == 0) {
            plVar10 = *(longlong **)(param_1 + 0x90);
            if (plVar10 != (longlong *)0x0) break;
            goto LAB_23e281020;
          }
          PyEval_SaveThread();
          PyEval_AcquireThread(param_1);
          plVar10 = *(longlong **)(param_1 + 0x90);
        } while (plVar10 == (longlong *)0x0);
        plVar11 = *(longlong **)(param_1 + 0x60);
        plVar4 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar5 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar10;
        *plVar10 = *plVar10 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))();
        }
        if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
          (**(code **)(plVar4[1] + 0x30))(plVar4);
        }
        if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        pcVar12 = *(code **)(param_1 + 0x60);
LAB_23e281175:
        local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
LAB_23e28117e:
        plVar10 = *(longlong **)(param_1 + 0x70);
        uVar13 = 0x3d;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar11 = DAT_23ed6a4f8;
        local_68._0_8_ = pcVar12;
      }
      goto joined_r0x00023e2811a5;
    }
  }
  local_68._0_8_ = *(undefined8 *)(param_1 + 0x60);
  local_68._8_8_ = *(undefined8 *)(param_1 + 0x68);
  plVar10 = *(longlong **)(param_1 + 0x70);
  uVar13 = 0x3b;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = DAT_23ed6a4f8;
joined_r0x00023e2811a5:
  DAT_23ed6a4f8 = plVar11;
  local_58[0] = plVar10;
  if (plVar10 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar12 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar7;
    plVar11[2] = 0;
    *plVar7 = *plVar7 + 1;
    lVar2 = *(longlong *)(pcVar12 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar13;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar11[-1];
    puVar6 = *(undefined8 **)(lVar2 + 8);
    *puVar6 = plVar11 + -2;
    plVar11[-2] = lVar2;
    plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar2 + 8) = plVar11 + -2;
    plVar10 = plVar11;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))(local_58[0]);
    }
  }
  else if ((longlong *)plVar10[3] != plVar7) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar12 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar2 = *(longlong *)(pcVar12 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar13;
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
    lVar3 = plVar11[-1];
    puVar6 = *(undefined8 **)(lVar2 + 8);
    *puVar6 = plVar11 + -2;
    plVar11[-2] = lVar2;
    plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar2 + 8) = plVar11 + -2;
    plVar11[2] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    plVar10 = plVar11;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))();
    }
  }
  local_58[0] = plVar10;
  FUN_23e8bba40(plVar7,&DAT_23ec5b149,plVar1);
  if (_DAT_23eeb05f8 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eeb05f8 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar2 + 0x28);
  plVar7 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_68._0_8_,local_68._8_8_,local_58[0]);
  return (code *)0x0;
}
