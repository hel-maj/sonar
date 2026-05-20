/* ===== 23e2e0080 ui.hotkey_dialog:162 ===== */
/* ghidra_name=FUN_23e2e0080 entry=23e2e0080 size=1856 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2e0080(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined4 uVar11;
  code *pcVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  
  plVar7 = _DAT_23eeb01e8;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb01e8 == (longlong *)0x0) {
LAB_23e2e00ba:
    _DAT_23eeb01e8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb01e0,DAT_23eeb0268,0x10);
  }
  else {
    lVar2 = *_DAT_23eeb01e8;
    if (1 < lVar2) {
      *_DAT_23eeb01e8 = lVar2 + -1;
      goto LAB_23e2e00ba;
    }
    if (_DAT_23eeb01e8[2] != 0) {
      *_DAT_23eeb01e8 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e2e00ba;
    }
  }
  plVar4 = _DAT_23eeb01e8;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eeb01e8 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb01e8[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar7;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar13 = DAT_23eead3f0;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  if (plVar7 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    uVar11 = 0xa4;
    plVar7 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = (longlong *)0x0;
  }
  else {
    iVar6 = FUN_23a35f020(plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (iVar6 == -1) {
      uVar13 = *(undefined8 *)(param_1 + 0x60);
      uVar14 = *(undefined8 *)(param_1 + 0x68);
      plVar9 = (longlong *)0x0;
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar11 = 0xa4;
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
    else if (iVar6 == 0) {
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead4e0);
      lVar2 = DAT_23eead4d8;
      if (plVar7 == (longlong *)0x0) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        uVar11 = 0xa5;
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar9 = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(plVar4 + 5) = 0xa5;
        plVar9 = (longlong *)
                 FUN_23e915840(param_1,plVar7,_DAT_23eead660,*(undefined8 *)(lVar2 + 0x18));
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          pcVar12 = _Py_NoneStruct_exref;
          lVar2 = *(longlong *)(param_1 + 0x38);
          lVar3 = *(longlong *)(lVar2 + 8);
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          plVar7 = *(longlong **)(lVar3 + 0x28);
          plVar4 = (longlong *)plVar7[2];
          *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(lVar3 + 0x30);
          *(undefined4 *)(plVar7 + 8) = 0xffffffff;
          if (plVar4 != (longlong *)0x0) {
            plVar7[2] = 0;
            *plVar4 = *plVar4 + -1;
            if (*plVar4 == 0) {
              (**(code **)(plVar4[1] + 0x30))();
            }
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar7[0xf] = 0;
LAB_23e2e0399:
          *plVar1 = *plVar1 + -1;
          if (*plVar1 != 0) {
            return pcVar12;
          }
          (**(code **)(plVar1[1] + 0x30))(plVar1);
          return pcVar12;
        }
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = (longlong *)0x0;
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar11 = 0xa5;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
    }
    else {
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eead628);
      if (plVar8 == (longlong *)0x0) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = (longlong *)0x0;
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar11 = 0xa8;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
      else {
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead3f0);
        if (plVar7 == (longlong *)0x0) {
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar14 = *(undefined8 *)(param_1 + 0x68);
          plVar7 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            plVar9 = (longlong *)0x0;
            (**(code **)(plVar8[1] + 0x30))(plVar8);
            uVar11 = 0xa8;
          }
          else {
            plVar9 = (longlong *)0x0;
            uVar11 = 0xa8;
          }
        }
        else {
          *(undefined4 *)(plVar4 + 5) = 0xa8;
          plVar9 = (longlong *)FUN_23e914090(param_1,plVar8,plVar7);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar9 == (longlong *)0x0) {
            uVar13 = *(undefined8 *)(param_1 + 0x60);
            uVar14 = *(undefined8 *)(param_1 + 0x68);
            uVar11 = 0xa8;
            plVar7 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
          }
          else {
            plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eead4e0);
            if (plVar7 != (longlong *)0x0) {
              *(undefined4 *)(plVar4 + 5) = 0xa9;
              plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,_DAT_23eead660,plVar9);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              if (plVar8 != (longlong *)0x0) {
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar7 = *(longlong **)(lVar2 + 0x28);
                plVar4 = (longlong *)plVar7[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
                *(undefined4 *)(plVar7 + 8) = 0xffffffff;
                if (plVar4 != (longlong *)0x0) {
                  plVar7[2] = 0;
                  *plVar4 = *plVar4 + -1;
                  if (*plVar4 == 0) {
                    (**(code **)(plVar4[1] + 0x30))();
                  }
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                plVar7[0xf] = 0;
                pcVar12 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                goto LAB_23e2e0399;
              }
            }
            plVar7 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar11 = 0xa9;
            uVar13 = *(undefined8 *)(param_1 + 0x60);
            uVar14 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
        }
      }
    }
  }
  plVar8 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = plVar8;
    }
    pcVar12 = _PyRuntime_exref;
    plVar10[3] = (longlong)plVar4;
    plVar10[2] = 0;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar12 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar11;
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar2;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar10 + -2;
  }
  else {
    plVar10 = plVar7;
    if ((longlong *)plVar7[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar10 = plVar8;
      }
      pcVar12 = _PyRuntime_exref;
      plVar10[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar12 + 0x1f8);
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar11;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar10[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar10 + -2;
      plVar10[-2] = lVar2;
      plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar7;
      *(longlong **)(lVar2 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar7;
      if (lVar3 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b14b,plVar1,plVar9);
  if (_DAT_23eeb01e8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb01e8 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar13,uVar14,plVar10);
  return (code *)0x0;
}
