/* ===== 23e2e6460 ui.hotkey_listener:43 ===== */
/* ghidra_name=FUN_23e2e6460 entry=23e2e6460 size=1854 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2e6460(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  longlong *plVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined4 uVar15;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar12 = _DAT_23eeb0178;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb0178 == (longlong *)0x0) {
LAB_23e2e649a:
    _DAT_23eeb0178 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0168,DAT_23eeb0170,8);
  }
  else {
    lVar13 = *_DAT_23eeb0178;
    if (1 < lVar13) {
      *_DAT_23eeb0178 = lVar13 + -1;
      goto LAB_23e2e649a;
    }
    if (_DAT_23eeb0178[2] != 0) {
      *_DAT_23eeb0178 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e2e649a;
    }
  }
  plVar4 = _DAT_23eeb0178;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eeb0178 + 9;
  lVar2 = *(longlong *)(lVar13 + 8);
  _DAT_23eeb0178[0xf] = lVar2;
  *(longlong **)(lVar13 + 8) = plVar12;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  pcVar9 = _Py_NoneStruct_exref;
  *(undefined4 *)(plVar4 + 8) = 0;
  cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eead0a0,pcVar9);
  if (cVar10 == '\0') {
    plVar12 = *(longlong **)(param_1 + 0x70);
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x2c;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar5 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = DAT_23ed6a4f8;
  }
  else {
    cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eead0a8,pcVar9);
    if (cVar10 == '\0') {
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = 0x2d;
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      uVar5 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = DAT_23ed6a4f8;
    }
    else {
      cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eead0b0,pcVar9);
      if (cVar10 == '\0') {
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0x2e;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar8 = DAT_23ed6a4f8;
      }
      else {
        plVar12 = (longlong *)PySet_New(0);
        cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eead0b8,plVar12);
        *plVar12 = *plVar12 + -1;
        pcVar7 = _Py_FalseStruct_exref;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          pcVar7 = _Py_FalseStruct_exref;
        }
        _Py_FalseStruct_exref = pcVar7;
        if (cVar10 == '\0') {
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          uVar5 = *(undefined8 *)(param_1 + 0x68);
          uVar15 = 0x2f;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar8 = DAT_23ed6a4f8;
        }
        else {
          cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eead0c0,pcVar7);
          if (cVar10 == '\0') {
            uVar6 = *(undefined8 *)(param_1 + 0x60);
            uVar5 = *(undefined8 *)(param_1 + 0x68);
            uVar15 = 0x30;
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar8 = DAT_23ed6a4f8;
          }
          else {
            lVar13 = FUN_23e8f5ec0();
            if (lVar13 == 0) {
              uVar15 = 0x31;
              FUN_23e915740(param_1,&uStack_68,DAT_23eead0c8);
              plVar12 = plStack_58;
              uVar6 = uStack_68;
              uVar5 = uStack_60;
              plVar8 = DAT_23ed6a4f8;
            }
            else {
              *(undefined4 *)(plVar4 + 5) = 0x31;
              plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar13,_DAT_23eead0d0);
              if (plVar12 != (longlong *)0x0) {
                cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eead0d8,plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (cVar10 != '\0') {
                  cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eead0e0,pcVar7);
                  if (cVar10 == '\0') {
                    uVar6 = *(undefined8 *)(param_1 + 0x60);
                    uVar15 = 0x32;
                    plVar12 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar5 = *(undefined8 *)(param_1 + 0x68);
                    plVar8 = DAT_23ed6a4f8;
                  }
                  else {
                    cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eead0e8,_Py_TrueStruct_exref);
                    if (cVar10 == '\0') {
                      uVar6 = *(undefined8 *)(param_1 + 0x60);
                      uVar15 = 0x33;
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar5 = *(undefined8 *)(param_1 + 0x68);
                      plVar8 = DAT_23ed6a4f8;
                    }
                    else {
                      lVar13 = *(longlong *)(param_1 + 0x10);
                      if (*(int *)(lVar13 + 0x1188) == 0) {
                        plVar12 = (longlong *)FUN_23a33a530(PyList_Type_exref);
                      }
                      else {
                        iVar11 = *(int *)(lVar13 + 0x1188) + -1;
                        *(int *)(lVar13 + 0x1188) = iVar11;
                        plVar12 = *(longlong **)(lVar13 + 0xf08 + (longlong)iVar11 * 8);
                        *plVar12 = 1;
                      }
                      pcVar7 = _PyRuntime_exref;
                      plVar12[2] = 0;
                      plVar12[4] = 0;
                      plVar12[3] = 0;
                      lVar13 = *(longlong *)
                                (*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
                      lVar2 = plVar12[-1];
                      puVar3 = *(undefined8 **)(lVar13 + 8);
                      *puVar3 = plVar12 + -2;
                      plVar12[-2] = lVar13;
                      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                      *(longlong **)(lVar13 + 8) = plVar12 + -2;
                      cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eead0f0,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      if (cVar10 != '\0') {
                        lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar12 = *(longlong **)(lVar13 + 0x28);
                        plVar4 = (longlong *)plVar12[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar13 + 0x30);
                        *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                        if (plVar4 != (longlong *)0x0) {
                          plVar12[2] = 0;
                          *plVar4 = *plVar4 + -1;
                          if (*plVar4 == 0) {
                            (**(code **)(plVar4[1] + 0x30))();
                          }
                        }
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                        plVar12[0xf] = 0;
                        *plVar1 = *plVar1 + -1;
                        if (*plVar1 != 0) {
                          return pcVar9;
                        }
                        (**(code **)(plVar1[1] + 0x30))(plVar1);
                        return pcVar9;
                      }
                      uVar6 = *(undefined8 *)(param_1 + 0x60);
                      uVar15 = 0x34;
                      plVar12 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar5 = *(undefined8 *)(param_1 + 0x68);
                      plVar8 = DAT_23ed6a4f8;
                    }
                  }
                  goto joined_r0x00023e2e6965;
                }
              }
              uVar6 = *(undefined8 *)(param_1 + 0x60);
              uVar15 = 0x31;
              plVar12 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = DAT_23ed6a4f8;
            }
          }
        }
      }
    }
  }
joined_r0x00023e2e6965:
  DAT_23ed6a4f8 = plVar8;
  if (plVar12 == (longlong *)0x0) {
    if (plVar8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar8;
      *plVar8 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar14 = plVar8;
    }
    pcVar9 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar13 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar2 = plVar14[-1];
    puVar3 = *(undefined8 **)(lVar13 + 8);
    *puVar3 = plVar14 + -2;
    plVar14[-2] = lVar13;
    plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar13 + 8) = plVar14 + -2;
  }
  else {
    plVar14 = plVar12;
    if ((longlong *)plVar12[3] != plVar4) {
      if (plVar8 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar8;
        *plVar8 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar14 = plVar8;
      }
      pcVar9 = _PyRuntime_exref;
      plVar14[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar13 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
      lVar2 = plVar14[-1];
      puVar3 = *(undefined8 **)(lVar13 + 8);
      *puVar3 = plVar14 + -2;
      plVar14[-2] = lVar13;
      plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      lVar2 = *plVar12;
      *(longlong **)(lVar13 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar12;
      if (lVar2 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b149,plVar1);
  if (_DAT_23eeb0178 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb0178 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar13 + 0x28);
  plVar4 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  plVar12[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar6,uVar5,plVar14);
  return (code *)0x0;
}
