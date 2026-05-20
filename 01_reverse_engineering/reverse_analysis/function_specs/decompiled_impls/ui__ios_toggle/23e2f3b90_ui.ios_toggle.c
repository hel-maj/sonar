/* ===== 23e2f3b90 ui.ios_toggle:46 ===== */
/* ghidra_name=FUN_23e2f3b90 entry=23e2f3b90 size=1864 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2f3b90(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  code *pcVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined4 uVar14;
  
  plVar11 = _DAT_23eeb0058;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeb0058 == (longlong *)0x0) {
LAB_23e2f3bce:
    _DAT_23eeb0058 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0050,DAT_23eeb0078,0x10);
  }
  else {
    lVar3 = *_DAT_23eeb0058;
    if (1 < lVar3) {
      *_DAT_23eeb0058 = lVar3 + -1;
      goto LAB_23e2f3bce;
    }
    if (_DAT_23eeb0058[2] != 0) {
      *_DAT_23eeb0058 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e2f3bce;
    }
  }
  plVar5 = _DAT_23eeb0058;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeb0058 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  _DAT_23eeb0058[0xf] = lVar4;
  *(longlong **)(lVar3 + 8) = plVar11;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar7 = DAT_23eeacdd8;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
  if (plVar11 != (longlong *)0x0) {
    *(undefined4 *)(plVar5 + 5) = 0x30;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eeace28);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      iVar10 = FUN_23a35f020(plVar2);
      if (iVar10 == -1) {
        uVar7 = *(undefined8 *)(param_1 + 0x60);
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0x31;
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = DAT_23ed6a4f8;
        goto joined_r0x00023e2f40c4;
      }
      if (iVar10 == 0) {
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeacdd8);
        if (plVar11 != (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeace30);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar13 != (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeacd68);
            if (plVar11 == (longlong *)0x0) {
              uVar7 = *(undefined8 *)(param_1 + 0x60);
              uVar8 = *(undefined8 *)(param_1 + 0x68);
              uVar14 = 0x34;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar13 = *plVar13 + -1;
              lVar3 = *plVar13;
              goto joined_r0x00023e2f42fd;
            }
            *(undefined4 *)(plVar5 + 5) = 0x34;
            plVar12 = (longlong *)FUN_23e914090(param_1,plVar13,plVar11);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar12 != (longlong *)0x0) goto LAB_23e2f3d5b;
          }
        }
        plVar11 = *(longlong **)(param_1 + 0x70);
        uVar7 = *(undefined8 *)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0x34;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = DAT_23ed6a4f8;
      }
      else {
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeacdd8);
        if (plVar11 != (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeace30);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar13 != (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeacd78);
            if (plVar11 == (longlong *)0x0) {
              uVar7 = *(undefined8 *)(param_1 + 0x60);
              uVar8 = *(undefined8 *)(param_1 + 0x68);
              uVar14 = 0x32;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar13 = *plVar13 + -1;
              lVar3 = *plVar13;
joined_r0x00023e2f42fd:
              plVar12 = DAT_23ed6a4f8;
              if (lVar3 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
                plVar12 = DAT_23ed6a4f8;
              }
              goto joined_r0x00023e2f40c4;
            }
            *(undefined4 *)(plVar5 + 5) = 0x32;
            plVar12 = (longlong *)FUN_23e914090(param_1,plVar13,plVar11);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar12 != (longlong *)0x0) {
LAB_23e2f3d5b:
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeacdd8);
              if (plVar11 != (longlong *)0x0) {
                *(undefined4 *)(plVar5 + 5) = 0x35;
                plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eeace38);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar12 != (longlong *)0x0) {
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar11 = *(longlong **)(lVar3 + 0x28);
                  plVar5 = (longlong *)plVar11[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30)
                  ;
                  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                  if (plVar5 != (longlong *)0x0) {
                    plVar11[2] = 0;
                    *plVar5 = *plVar5 + -1;
                    if (*plVar5 == 0) {
                      (**(code **)(plVar5[1] + 0x30))();
                    }
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  plVar11[0xf] = 0;
                  pcVar9 = _Py_NoneStruct_exref;
                  *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                  *plVar1 = *plVar1 + -1;
                  if (*plVar1 == 0) {
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                  }
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 != 0) {
                    return pcVar9;
                  }
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                  return pcVar9;
                }
              }
              uVar7 = *(undefined8 *)(param_1 + 0x60);
              uVar8 = *(undefined8 *)(param_1 + 0x68);
              uVar14 = 0x35;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar12 = DAT_23ed6a4f8;
              goto joined_r0x00023e2f40c4;
            }
          }
        }
        uVar7 = *(undefined8 *)(param_1 + 0x60);
        uVar8 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0x32;
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e2f40c4;
    }
  }
  plVar11 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar14 = 0x30;
  uVar7 = *(undefined8 *)(param_1 + 0x60);
  uVar8 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar12 = DAT_23ed6a4f8;
joined_r0x00023e2f40c4:
  DAT_23ed6a4f8 = plVar12;
  if (plVar11 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar12;
    }
    pcVar9 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar3 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
    lVar3 = *(longlong *)(lVar3 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar3 = *(longlong *)(lVar3 + 0x2e8);
    lVar4 = plVar13[-1];
    puVar6 = *(undefined8 **)(lVar3 + 8);
    *puVar6 = plVar13 + -2;
    plVar13[-2] = lVar3;
    plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar3 + 8) = plVar13 + -2;
  }
  else {
    plVar13 = plVar11;
    if ((longlong *)plVar11[3] != plVar5) {
      if (plVar12 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar12;
      }
      pcVar9 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar3 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
      lVar4 = plVar13[-1];
      puVar6 = *(undefined8 **)(lVar3 + 8);
      *puVar6 = plVar13 + -2;
      plVar13[-2] = lVar3;
      plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar11;
      *(longlong **)(lVar3 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar11;
      if (lVar4 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5b14b,plVar1,plVar2);
  if (_DAT_23eeb0058 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb0058 = (longlong *)0x0;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar3 + 0x28);
  plVar5 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar7,uVar8,plVar13);
  return (code *)0x0;
}
