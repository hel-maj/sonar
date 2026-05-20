/* ===== 23e2ae3f0 ui.garbage_settings_dialog:c1141 ===== */
/* ghidra_name=FUN_23e2ae3f0 entry=23e2ae3f0 size=1477 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2ae3f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  char cVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  longlong *plVar15;
  
  plVar8 = _DAT_23eeb03d0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb03d0 == (longlong *)0x0) {
LAB_23e2ae42a:
    _DAT_23eeb03d0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0450,DAT_23eeb0428,0x18);
  }
  else {
    lVar2 = *_DAT_23eeb03d0;
    if (1 < lVar2) {
      *_DAT_23eeb03d0 = lVar2 + -1;
      goto LAB_23e2ae42a;
    }
    if (_DAT_23eeb03d0[2] != 0) {
      *_DAT_23eeb03d0 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e2ae42a;
    }
  }
  plVar4 = _DAT_23eeb03d0;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeb03d0 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb03d0[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar8;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar13 = _DAT_23eeae560;
  *(undefined4 *)(plVar4 + 8) = 0;
  *(undefined4 *)(plVar4 + 5) = 0xa7;
  plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar13);
  if (plVar8 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    plVar10 = (longlong *)0x0;
    uVar12 = 0xa7;
    plVar9 = *(longlong **)(param_1 + 0x70);
  }
  else {
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeae450);
    if (plVar9 == (longlong *)0x0) {
      uVar13 = *(undefined8 *)(param_1 + 0x60);
      uVar14 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = (longlong *)0x0;
      uVar12 = 0xaa;
      plVar9 = *(longlong **)(param_1 + 0x70);
    }
    else {
      *(undefined4 *)(plVar4 + 5) = 0xaa;
      plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,_DAT_23eeae568);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 == (longlong *)0x0) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        uVar12 = 0xaa;
        plVar9 = *(longlong **)(param_1 + 0x70);
      }
      else {
        cVar7 = FUN_23a39bc50(param_1,plVar10,_DAT_23eeae570,plVar8);
        if (cVar7 == '\0') {
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar14 = *(undefined8 *)(param_1 + 0x68);
          uVar12 = 0xad;
          plVar9 = *(longlong **)(param_1 + 0x70);
        }
        else {
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeae450);
          if (plVar9 != (longlong *)0x0) {
            *(undefined4 *)(plVar4 + 5) = 0xb0;
            plVar11 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeae578,plVar10);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar11 != (longlong *)0x0) {
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *(undefined4 *)(plVar4 + 5) = 0xb2;
              plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23eeae580);
              if (plVar9 != (longlong *)0x0) {
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar4 = *(longlong **)(lVar2 + 0x28);
                plVar9 = (longlong *)plVar4[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
                *(undefined4 *)(plVar4 + 8) = 0xffffffff;
                if (plVar9 != (longlong *)0x0) {
                  plVar4[2] = 0;
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))();
                  }
                }
                *plVar4 = *plVar4 + -1;
                if (*plVar4 == 0) {
                  (**(code **)(plVar4[1] + 0x30))(plVar4);
                }
                plVar4[0xf] = 0;
                pcVar6 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar1 = *plVar1 + -1;
                if (*plVar1 != 0) {
                  return pcVar6;
                }
                (**(code **)(plVar1[1] + 0x30))(plVar1);
                return pcVar6;
              }
              uVar13 = *(undefined8 *)(param_1 + 0x60);
              uVar14 = *(undefined8 *)(param_1 + 0x68);
              uVar12 = 0xb2;
              plVar9 = *(longlong **)(param_1 + 0x70);
              goto LAB_23e2ae6d1;
            }
          }
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar14 = *(undefined8 *)(param_1 + 0x68);
          uVar12 = 0xb0;
          plVar9 = *(longlong **)(param_1 + 0x70);
        }
      }
    }
  }
LAB_23e2ae6d1:
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = DAT_23ed6a4f8;
  if (plVar9 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar11[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar11 + -2;
    plVar11[-2] = lVar2;
    plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar11 + -2;
    plVar15 = plVar11;
  }
  else {
    plVar15 = plVar9;
    if ((longlong *)plVar9[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar11[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
      pcVar6 = _PyRuntime_exref;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar11[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar11 + -2;
      plVar11[-2] = lVar2;
      plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar9;
      *(longlong **)(lVar2 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      plVar15 = plVar11;
      if (lVar3 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b355,plVar1,plVar8,plVar10);
  if (_DAT_23eeb03d0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb03d0 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar2 + 0x28);
  plVar9 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar13,uVar14,plVar15);
  return (code *)0x0;
}
