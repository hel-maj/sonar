/* ===== 23e6fe010 workers.fishing.casting_a_fishin:236 ===== */
/* ghidra_name=FUN_23e6fe010 entry=23e6fe010 size=3267 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e6fe010(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  code *pcVar9;
  int iVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong **pplStack_80;
  longlong *plStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  undefined4 uVar16;
  
  plVar12 = _DAT_23eedb1b0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eedb1b0 == (longlong *)0x0) {
LAB_23e6fe053:
    _DAT_23eedb1b0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb1a8,DAT_23eedb268,0x10);
  }
  else {
    lVar11 = *_DAT_23eedb1b0;
    if (1 < lVar11) {
      *_DAT_23eedb1b0 = lVar11 + -1;
      goto LAB_23e6fe053;
    }
    if (_DAT_23eedb1b0[2] != 0) {
      *_DAT_23eedb1b0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e6fe053;
    }
  }
  plVar6 = _DAT_23eedb1b0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eedb1b0 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  _DAT_23eedb1b0[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar12;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar8 = _DAT_23eeda628;
  *(undefined4 *)(plVar6 + 8) = 0;
  iVar10 = FUN_23e97a530(plVar1,uVar8);
  if (iVar10 == -1) {
LAB_23e6fe9d8:
    plVar12 = *(longlong **)(param_1 + 0x70);
    plVar7 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = DAT_23ed6a4f8;
    uVar16 = 0xee;
    goto joined_r0x00023e6fe9fc;
  }
  if (iVar10 == 1) {
    iVar10 = FUN_23e97a530(plVar2,_DAT_23eeda630);
    plVar12 = _DAT_23eeda638;
    if (iVar10 == -1) goto LAB_23e6fe9d8;
    if (iVar10 == 1) {
      lVar11 = *(longlong *)(param_1 + 0x10);
      plVar14 = *(longlong **)(lVar11 + 0xe20);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar3 = plVar14[3];
        *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
        *(longlong *)(lVar11 + 0xe20) = lVar3;
        *plVar14 = 1;
      }
      pcVar9 = _PyRuntime_exref;
      plVar14[4] = 0;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar14[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar14 + -2;
      plVar14[-2] = lVar11;
      plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar11 + 8) = plVar14 + -2;
      *plVar12 = *plVar12 + 1;
      plVar14[3] = (longlong)plVar12;
      plVar12 = (longlong *)FUN_23e8e1710();
      if (plVar12 != (longlong *)0x0) goto LAB_23e6fe548;
      FUN_23e915740(param_1,&plStack_78,_DAT_23eeda640);
      uVar8 = uStack_70;
      plVar7 = plStack_78;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      uVar16 = 0xef;
      plVar12 = plStack_68;
      plVar14 = DAT_23ed6a4f8;
      goto joined_r0x00023e6fe9fc;
    }
  }
  iVar10 = FUN_23e97a530(plVar1,_DAT_23eeda648);
  if (iVar10 == -1) {
LAB_23e6feab8:
    plVar7 = *(longlong **)(param_1 + 0x60);
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    uVar16 = 0xf0;
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar14 = DAT_23ed6a4f8;
    goto joined_r0x00023e6fe9fc;
  }
  if (iVar10 == 1) {
    iVar10 = FUN_23e97a530(plVar2,_DAT_23eeda650);
    plVar12 = _DAT_23eeda658;
    if (iVar10 == -1) goto LAB_23e6feab8;
    if (iVar10 == 1) {
      lVar11 = *(longlong *)(param_1 + 0x10);
      plVar14 = *(longlong **)(lVar11 + 0xe20);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar3 = plVar14[3];
        *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
        *(longlong *)(lVar11 + 0xe20) = lVar3;
        *plVar14 = 1;
      }
      pcVar9 = _PyRuntime_exref;
      plVar14[4] = 0;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar14[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar14 + -2;
      plVar14[-2] = lVar11;
      plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar11 + 8) = plVar14 + -2;
      *plVar12 = *plVar12 + 1;
      plVar14[3] = (longlong)plVar12;
      plVar12 = (longlong *)FUN_23e8e15c0();
      if (plVar12 == (longlong *)0x0) {
        FUN_23e915740(param_1,&plStack_78,_DAT_23eeda660);
        uVar8 = uStack_70;
        plVar7 = plStack_78;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        uVar16 = 0xf1;
        plVar12 = plStack_68;
        plVar14 = DAT_23ed6a4f8;
        goto joined_r0x00023e6fe9fc;
      }
      goto LAB_23e6fe548;
    }
  }
  iVar10 = FUN_23e97c2c0(plVar1,_DAT_23eeda668);
  plVar12 = _DAT_23eeda670;
  if (iVar10 == -1) {
    plVar7 = *(longlong **)(param_1 + 0x60);
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    uVar16 = 0xf4;
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar14 = DAT_23ed6a4f8;
    goto joined_r0x00023e6fe9fc;
  }
  lVar11 = *(longlong *)(param_1 + 0x10);
  plVar13 = *(longlong **)(lVar11 + 0xe38);
  if (iVar10 == 1) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
    }
    else {
      lVar3 = plVar13[3];
      *(int *)(lVar11 + 0xec8) = *(int *)(lVar11 + 0xec8) + -1;
      *(longlong *)(lVar11 + 0xe38) = lVar3;
      *plVar13 = 1;
    }
    pcVar9 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar13 + 4) = (undefined1  [16])0x0;
    lVar11 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined1 (*) [16])(plVar13 + 6) = (undefined1  [16])0x0;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar13[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar13 + -2;
    plVar13[-2] = lVar11;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar13 + -2;
    *plVar12 = *plVar12 + 1;
    plVar13[3] = (longlong)plVar12;
    uVar8 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar12 == (longlong *)0x0) goto LAB_23e6fec70;
      *plVar12 = *plVar12 + 1;
      DAT_23ed6a4c0 = plVar12;
    }
    uStack_70 = uVar8;
    plStack_78 = plVar1;
    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
    if (lVar11 != 0) {
      plVar13[4] = lVar11;
      plVar7 = _DAT_23eeda678;
      plVar12 = DAT_23ed6a4c0;
      *_DAT_23eeda678 = *_DAT_23eeda678 + 1;
      plVar13[5] = (longlong)plVar7;
      uVar8 = DAT_23ed6cd28;
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar12 == (longlong *)0x0) goto LAB_23e6fec70;
        *plVar12 = *plVar12 + 1;
        DAT_23ed6a4c0 = plVar12;
      }
      pplStack_80 = &plStack_78;
      uStack_70 = uVar8;
      plStack_78 = plVar2;
      lVar11 = FUN_23e94ed00(param_1,plVar12,pplStack_80);
      if (lVar11 == 0) goto LAB_23e6feae0;
      plVar13[6] = lVar11;
      plVar12 = _DAT_23eeda680;
      *_DAT_23eeda680 = *_DAT_23eeda680 + 1;
      plVar13[7] = (longlong)plVar12;
      lVar11 = PyUnicode_Join(DAT_23ed6cd28,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (lVar11 != 0) {
        lVar3 = *(longlong *)(param_1 + 0x10);
        plVar14 = *(longlong **)(lVar3 + 0xe20);
        if (plVar14 == (longlong *)0x0) {
          plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar5 = plVar14[3];
          *(int *)(lVar3 + 0xebc) = *(int *)(lVar3 + 0xebc) + -1;
          *(longlong *)(lVar3 + 0xe20) = lVar5;
          *plVar14 = 1;
        }
        lVar3 = *(longlong *)(pcVar9 + 0x1f8);
        plVar14[4] = 0;
        lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
        lVar5 = plVar14[-1];
        puVar4 = *(undefined8 **)(lVar3 + 8);
        *puVar4 = plVar14 + -2;
        plVar14[-2] = lVar3;
        plVar14[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar3 + 8) = plVar14 + -2;
        plVar14[3] = lVar11;
        plVar12 = (longlong *)FUN_23e8e1710();
        if (plVar12 != (longlong *)0x0) goto LAB_23e6fe548;
        FUN_23e915740(param_1,pplStack_80,_DAT_23eeda640);
        uVar8 = uStack_70;
        plVar7 = plStack_78;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        uVar16 = 0xf5;
        plVar12 = plStack_68;
        plVar14 = DAT_23ed6a4f8;
        goto joined_r0x00023e6fe9fc;
      }
      goto LAB_23e6fec88;
    }
LAB_23e6feae0:
    plVar7 = *(longlong **)(param_1 + 0x60);
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    uVar16 = 0xf5;
    uVar15 = 0xf5;
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar13 = *plVar13 + -1;
    lVar11 = *plVar13;
  }
  else {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
    }
    else {
      lVar3 = plVar13[3];
      *(int *)(lVar11 + 0xec8) = *(int *)(lVar11 + 0xec8) + -1;
      *(longlong *)(lVar11 + 0xe38) = lVar3;
      *plVar13 = 1;
    }
    pcVar9 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar13 + 4) = (undefined1  [16])0x0;
    lVar11 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined1 (*) [16])(plVar13 + 6) = (undefined1  [16])0x0;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar13[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar13 + -2;
    plVar13[-2] = lVar11;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar13 + -2;
    *plVar12 = *plVar12 + 1;
    plVar13[3] = (longlong)plVar12;
    uVar8 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar12 != (longlong *)0x0) {
        *plVar12 = *plVar12 + 1;
        DAT_23ed6a4c0 = plVar12;
        goto LAB_23e6fe1eb;
      }
LAB_23e6fec70:
      PyErr_PrintEx(0,0);
      Py_Exit(1);
LAB_23e6fec88:
      plVar7 = *(longlong **)(param_1 + 0x60);
      uVar8 = *(undefined8 *)(param_1 + 0x68);
      uVar16 = 0xf5;
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar14 = DAT_23ed6a4f8;
      goto joined_r0x00023e6fe9fc;
    }
LAB_23e6fe1eb:
    uStack_70 = uVar8;
    plStack_78 = plVar1;
    lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
    if (lVar11 != 0) {
      plVar13[4] = lVar11;
      plVar7 = _DAT_23eeda678;
      plVar12 = DAT_23ed6a4c0;
      *_DAT_23eeda678 = *_DAT_23eeda678 + 1;
      plVar13[5] = (longlong)plVar7;
      uVar8 = DAT_23ed6cd28;
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar12 == (longlong *)0x0) goto LAB_23e6fec70;
        *plVar12 = *plVar12 + 1;
        DAT_23ed6a4c0 = plVar12;
      }
      uStack_70 = uVar8;
      plStack_78 = plVar2;
      lVar11 = FUN_23e94ed00(param_1,plVar12,&plStack_78);
      if (lVar11 != 0) {
        plVar13[6] = lVar11;
        plVar12 = _DAT_23eeda688;
        *_DAT_23eeda688 = *_DAT_23eeda688 + 1;
        plVar13[7] = (longlong)plVar12;
        lVar11 = PyUnicode_Join(DAT_23ed6cd28,plVar13);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (lVar11 == 0) {
          plVar7 = *(longlong **)(param_1 + 0x60);
          uVar8 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar14 = DAT_23ed6a4f8;
          uVar16 = 0xf7;
        }
        else {
          lVar3 = *(longlong *)(param_1 + 0x10);
          plVar14 = *(longlong **)(lVar3 + 0xe20);
          if (plVar14 == (longlong *)0x0) {
            plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar5 = plVar14[3];
            *(int *)(lVar3 + 0xebc) = *(int *)(lVar3 + 0xebc) + -1;
            *(longlong *)(lVar3 + 0xe20) = lVar5;
            *plVar14 = 1;
          }
          lVar3 = *(longlong *)(pcVar9 + 0x1f8);
          plVar14[4] = 0;
          lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
          lVar5 = plVar14[-1];
          puVar4 = *(undefined8 **)(lVar3 + 8);
          *puVar4 = plVar14 + -2;
          plVar14[-2] = lVar3;
          plVar14[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar4;
          *(longlong **)(lVar3 + 8) = plVar14 + -2;
          plVar14[3] = lVar11;
          plVar12 = (longlong *)FUN_23e8e15c0();
          if (plVar12 != (longlong *)0x0) {
LAB_23e6fe548:
            *plVar12 = *plVar12 + 1;
            plVar14[4] = (longlong)plVar12;
            lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar12 = *(longlong **)(lVar11 + 0x28);
            plVar6 = (longlong *)plVar12[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
            *(undefined4 *)(plVar12 + 8) = 0xffffffff;
            if (plVar6 != (longlong *)0x0) {
              plVar12[2] = 0;
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))();
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
            *plVar2 = *plVar2 + -1;
            if (*plVar2 == 0) {
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return plVar14;
            }
            return plVar14;
          }
          FUN_23e915740(param_1,&plStack_78,_DAT_23eeda660);
          uVar8 = uStack_70;
          plVar7 = plStack_78;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          plVar12 = plStack_68;
          plVar14 = DAT_23ed6a4f8;
          uVar16 = 0xf7;
        }
        goto joined_r0x00023e6fe9fc;
      }
    }
    plVar7 = *(longlong **)(param_1 + 0x60);
    uVar8 = *(undefined8 *)(param_1 + 0x68);
    uVar16 = 0xf7;
    uVar15 = 0xf7;
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar13 = *plVar13 + -1;
    lVar11 = *plVar13;
  }
  plVar14 = DAT_23ed6a4f8;
  if (lVar11 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
    plVar14 = DAT_23ed6a4f8;
    uVar16 = uVar15;
  }
joined_r0x00023e6fe9fc:
  DAT_23ed6a4f8 = plVar14;
  if (plVar12 == (longlong *)0x0) {
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar14;
      *plVar14 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar11 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar16;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar3 = plVar14[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar14 + -2;
    plVar14[-2] = lVar11;
    plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar14 + -2;
    plVar13 = plVar14;
  }
  else {
    plVar13 = plVar12;
    if ((longlong *)plVar12[3] != plVar6) {
      if (plVar14 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar14;
        *plVar14 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar9 = _PyRuntime_exref;
      plVar14[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      lVar11 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar16;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar3 = plVar14[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar14 + -2;
      plVar14[-2] = lVar11;
      plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      lVar3 = *plVar12;
      *(longlong **)(lVar11 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar12;
      plVar13 = plVar14;
      if (lVar3 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar6,&DAT_23ec5dd15,plVar1,plVar2);
  if (_DAT_23eedb1b0 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eedb1b0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar12 = *(longlong **)(lVar11 + 0x28);
  plVar6 = (longlong *)plVar12[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
  if (plVar6 != (longlong *)0x0) {
    plVar12[2] = 0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
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
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar7,uVar8,plVar13);
  return (longlong *)0x0;
}
