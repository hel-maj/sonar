/* ===== 23c63af70 license.license_client:436 ===== */
/* ghidra_name=FUN_23c63af70 entry=23c63af70 size=1778 */

code * FUN_23c63af70(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong *plVar7;
  code *pcVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  
  plVar7 = DAT_23ee29c20;
  plVar1 = (longlong *)*param_3;
  if (DAT_23ee29c20 == (longlong *)0x0) {
LAB_23c63afaa:
    DAT_23ee29c20 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29c18,DAT_23ee29d18,8);
  }
  else {
    lVar2 = *DAT_23ee29c20;
    if (1 < lVar2) {
      *DAT_23ee29c20 = lVar2 + -1;
      goto LAB_23c63afaa;
    }
    if (DAT_23ee29c20[2] != 0) {
      *DAT_23ee29c20 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23c63afaa;
    }
  }
  plVar4 = DAT_23ee29c20;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23ee29c20 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  DAT_23ee29c20[0xf] = lVar3;
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
  uVar11 = DAT_23ee283a8;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
  if (plVar7 != (longlong *)0x0) {
    iVar6 = FUN_23a35f020(plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    pcVar8 = _Py_NoneStruct_exref;
    uVar11 = DAT_23ee28688;
    if (iVar6 != -1) {
      if (iVar6 == 0) {
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
LAB_23c63b07b:
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
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar8;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar8;
      }
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee28390);
      if (plVar7 == (longlong *)0x0) {
        uVar11 = *(undefined8 *)(param_1 + 0x60);
        uVar12 = *(undefined8 *)(param_1 + 0x68);
        uVar13 = 0x1ba;
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23c63b392;
      }
      pcVar8 = (code *)_PyDict_NewPresized(5);
      PyDict_SetItem(pcVar8,uVar11,plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      uVar11 = DAT_23ee286c0;
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a8);
      if (plVar7 == (longlong *)0x0) {
LAB_23c63b4e8:
        uVar11 = *(undefined8 *)(param_1 + 0x60);
        uVar12 = *(undefined8 *)(param_1 + 0x68);
        uVar13 = 0x1bb;
        plVar7 = *(longlong **)(param_1 + 0x70);
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6ce40);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23c63b4e8;
        *(undefined4 *)(plVar4 + 5) = 0x1bb;
        plVar7 = (longlong *)FUN_23e94bb80(param_1,plVar9,DAT_23ee28578);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar7 == (longlong *)0x0) goto LAB_23c63b4e8;
        PyDict_SetItem(pcVar8,uVar11,plVar7);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        uVar11 = DAT_23ee286c8;
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a8);
        if (plVar7 == (longlong *)0x0) {
LAB_23c63b5f0:
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          uVar12 = *(undefined8 *)(param_1 + 0x68);
          uVar13 = 0x1bc;
          plVar7 = *(longlong **)(param_1 + 0x70);
        }
        else {
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6ce40);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar9 == (longlong *)0x0) goto LAB_23c63b5f0;
          *(undefined4 *)(plVar4 + 5) = 0x1bc;
          plVar7 = (longlong *)FUN_23e94bb80(param_1,plVar9,DAT_23ee286d0);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar7 == (longlong *)0x0) goto LAB_23c63b5f0;
          PyDict_SetItem(pcVar8,uVar11,plVar7);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          uVar11 = DAT_23ee28450;
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a0);
          if (plVar7 == (longlong *)0x0) {
            uVar11 = *(undefined8 *)(param_1 + 0x60);
            uVar12 = *(undefined8 *)(param_1 + 0x68);
            uVar13 = 0x1bd;
            plVar7 = *(longlong **)(param_1 + 0x70);
          }
          else {
            PyDict_SetItem(pcVar8,uVar11,plVar7);
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            uVar11 = DAT_23ee289c0;
            *(undefined4 *)(plVar4 + 5) = 0x1be;
            plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar11);
            if (plVar7 != (longlong *)0x0) {
              PyDict_SetItem(pcVar8,uVar11,plVar7);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              goto LAB_23c63b07b;
            }
            uVar11 = *(undefined8 *)(param_1 + 0x60);
            uVar12 = *(undefined8 *)(param_1 + 0x68);
            uVar13 = 0x1be;
            plVar7 = *(longlong **)(param_1 + 0x70);
          }
        }
      }
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
      if (*(longlong *)pcVar8 == 0) {
        (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
      }
      goto LAB_23c63b392;
    }
  }
  plVar7 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar13 = 0x1b6;
  uVar11 = *(undefined8 *)(param_1 + 0x60);
  uVar12 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c63b392:
  plVar9 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar4;
    plVar9[2] = 0;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar2;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar9 + -2;
    plVar10 = plVar9;
  }
  else {
    plVar10 = plVar7;
    if ((longlong *)plVar7[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar8 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar9[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar9 + -2;
      plVar9[-2] = lVar2;
      plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar7;
      *(longlong **)(lVar2 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar7;
      plVar10 = plVar9;
      if (lVar3 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec47964,plVar1);
  if (DAT_23ee29c20 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23ee29c20 = (longlong *)0x0;
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
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar11,uVar12,plVar10);
  return (code *)0x0;
}
