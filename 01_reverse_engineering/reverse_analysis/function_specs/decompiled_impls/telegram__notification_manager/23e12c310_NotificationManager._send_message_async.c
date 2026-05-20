/* ===== 23e12c310 telegram.notification_manager:17 ===== */
/* ghidra_name=forced_23e12c310 entry=23e12c310 size=1748 */

code * forced_23e12c310(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  code *pcVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar12 = DAT_23eeaae10;
  plVar1 = (longlong *)*param_3;
  if (DAT_23eeaae10 == (longlong *)0x0) {
LAB_23e12c34a:
    DAT_23eeaae10 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaae00,DAT_23eeaae08,8);
  }
  else {
    lVar14 = *DAT_23eeaae10;
    if (1 < lVar14) {
      *DAT_23eeaae10 = lVar14 + -1;
      goto LAB_23e12c34a;
    }
    if (DAT_23eeaae10[2] != 0) {
      *DAT_23eeaae10 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e12c34a;
    }
  }
  plVar4 = DAT_23eeaae10;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar12 = DAT_23eeaae10 + 9;
  lVar2 = *(longlong *)(lVar14 + 8);
  DAT_23eeaae10[0xf] = lVar2;
  *(longlong **)(lVar14 + 8) = plVar12;
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
  lVar2 = DAT_23eea8118;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar14 = *(longlong *)(lVar2 + 0x20);
  if (*(char *)(lVar14 + 10) == '\0') {
    plVar12 = (longlong *)FUN_23a37a020(lVar2,DAT_23eea8120);
    if (plVar12 == (longlong *)0x0) goto LAB_23e12c609;
    lVar14 = *plVar12;
LAB_23e12c9b0:
    if (lVar14 == 0) goto LAB_23e12c609;
  }
  else {
    iVar11 = *(int *)(lVar14 + 0xc);
    if (*(int *)(lVar14 + 0xc) == 0) {
      *(int *)(lVar14 + 0xc) = DAT_23ec14c1c;
      iVar11 = DAT_23ec14c1c;
      DAT_23ec14c1c = DAT_23ec14c1c + 1;
    }
    if (DAT_23ec14c20 != iVar11) {
      DAT_23ec14c20 = iVar11;
      DAT_23eeaadf8 = FUN_23e8cbd60(lVar14,DAT_23eea8120,*(undefined8 *)(DAT_23eea8120 + 0x18));
    }
    if (-1 < DAT_23eeaadf8) {
      lVar2 = lVar14 + 0x20 + (1L << (*(byte *)(lVar14 + 9) & 0x3f));
      if (*(longlong *)(lVar2 + 8 + DAT_23eeaadf8 * 0x10) != 0) goto LAB_23e12c43a;
      DAT_23eeaadf8 = FUN_23e8cbd60(lVar14,DAT_23eea8120,*(undefined8 *)(DAT_23eea8120 + 0x18));
      if (-1 < DAT_23eeaadf8) {
        lVar14 = *(longlong *)(lVar2 + 8 + DAT_23eeaadf8 * 0x10);
        goto LAB_23e12c9b0;
      }
    }
LAB_23e12c609:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8120);
    if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
      uVar15 = 0x12;
      FUN_23e915740(param_1,&uStack_68,DAT_23eea8120);
      plVar12 = plStack_58;
      uVar5 = uStack_68;
      uVar6 = uStack_60;
      plVar7 = DAT_23ed6a4f8;
      goto joined_r0x00023e12c755;
    }
  }
LAB_23e12c43a:
  *(undefined4 *)(plVar4 + 5) = 0x12;
  plVar12 = (longlong *)FUN_23e91a870(param_1);
  if (plVar12 != (longlong *)0x0) {
    cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eea8128,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    pcVar8 = _Py_NoneStruct_exref;
    if (cVar10 != '\0') {
      cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eea8130,_Py_NoneStruct_exref);
      if (cVar10 == '\0') {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar15 = 0x13;
        plVar12 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar7 = DAT_23ed6a4f8;
      }
      else {
        lVar14 = *(longlong *)(param_1 + 0x10);
        if (*(int *)(lVar14 + 0x1188) == 0) {
          plVar12 = (longlong *)FUN_23a33a530(PyList_Type_exref);
        }
        else {
          iVar11 = *(int *)(lVar14 + 0x1188) + -1;
          *(int *)(lVar14 + 0x1188) = iVar11;
          plVar12 = *(longlong **)(lVar14 + 0xf08 + (longlong)iVar11 * 8);
          *plVar12 = 1;
        }
        pcVar9 = _PyRuntime_exref;
        plVar12[2] = 0;
        plVar12[4] = 0;
        lVar14 = *(longlong *)(pcVar9 + 0x1f8);
        plVar12[3] = 0;
        lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
        lVar2 = plVar12[-1];
        puVar3 = *(undefined8 **)(lVar14 + 8);
        *puVar3 = plVar12 + -2;
        plVar12[-2] = lVar14;
        plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
        *(longlong **)(lVar14 + 8) = plVar12 + -2;
        cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eea8138,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (cVar10 == '\0') {
          uVar5 = *(undefined8 *)(param_1 + 0x60);
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          uVar15 = 0x14;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar7 = DAT_23ed6a4f8;
        }
        else {
          cVar10 = FUN_23e8d9ac0(plVar1,DAT_23eea8140,pcVar8);
          if (cVar10 != '\0') {
            lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar12 = *(longlong **)(lVar14 + 0x28);
            plVar4 = (longlong *)plVar12[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
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
            *(longlong *)pcVar8 = *(longlong *)pcVar8 + 1;
            plVar12[0xf] = 0;
            *plVar1 = *plVar1 + -1;
            if (*plVar1 != 0) {
              return pcVar8;
            }
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar8;
          }
          uVar5 = *(undefined8 *)(param_1 + 0x60);
          uVar6 = *(undefined8 *)(param_1 + 0x68);
          uVar15 = 0x15;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar7 = DAT_23ed6a4f8;
        }
      }
      goto joined_r0x00023e12c755;
    }
  }
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar15 = 0x12;
  uVar5 = *(undefined8 *)(param_1 + 0x60);
  uVar6 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar7 = DAT_23ed6a4f8;
joined_r0x00023e12c755:
  DAT_23ed6a4f8 = plVar7;
  if (plVar12 == (longlong *)0x0) {
    if (plVar7 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar7;
      *plVar7 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar7;
    }
    pcVar8 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar14 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar2 = plVar13[-1];
    puVar3 = *(undefined8 **)(lVar14 + 8);
    *puVar3 = plVar13 + -2;
    plVar13[-2] = lVar14;
    plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar14 + 8) = plVar13 + -2;
  }
  else {
    plVar13 = plVar12;
    if ((longlong *)plVar12[3] != plVar4) {
      if (plVar7 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar7;
        *plVar7 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar7;
      }
      pcVar8 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar14 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
      lVar2 = plVar13[-1];
      puVar3 = *(undefined8 **)(lVar14 + 8);
      *puVar3 = plVar13 + -2;
      plVar13[-2] = lVar14;
      plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      lVar2 = *plVar12;
      *(longlong **)(lVar14 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar12;
      if (lVar2 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5a08d,plVar1);
  if (DAT_23eeaae10 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eeaae10 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar14 + 0x28);
  plVar4 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
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
  FUN_23a33aa70(param_1,uVar5,uVar6,plVar13);
  return (code *)0x0;
}
