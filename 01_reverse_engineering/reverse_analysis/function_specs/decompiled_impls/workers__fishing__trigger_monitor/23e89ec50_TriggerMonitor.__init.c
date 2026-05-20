/* ===== 23e89ec50 workers.fishing.trigger_monitor:254 ===== */
/* ghidra_name=FUN_23e89ec50 entry=23e89ec50 size=5484 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e89ec50(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  longlong *plStack_a0;
  longlong *plStack_98;
  code *pcStack_88;
  longlong *plStack_80;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar9 = _DAT_23eede470;
  pcVar1 = (code *)param_3[1];
  plVar2 = (longlong *)*param_3;
  plStack_68 = (longlong *)0x0;
  auStack_78._0_8_ = 0;
  auStack_78._8_8_ = 0;
  if (_DAT_23eede470 == (longlong *)0x0) {
LAB_23e89ecb6:
    _DAT_23eede470 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede468,DAT_23eede5a0,0x30);
  }
  else {
    lVar15 = *_DAT_23eede470;
    if (1 < lVar15) {
      *_DAT_23eede470 = lVar15 + -1;
      goto LAB_23e89ecb6;
    }
    if (_DAT_23eede470[2] != 0) {
      *_DAT_23eede470 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e89ecb6;
    }
  }
  plVar4 = _DAT_23eede470;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede470 + 9;
  lVar3 = *(longlong *)(lVar15 + 8);
  _DAT_23eede470[0xf] = lVar3;
  *(longlong **)(lVar15 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar18 = _DAT_23eedc270;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,uVar18);
  if (plVar9 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar11 = (code *)0x0;
    uVar17 = 0x100;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
    plVar14 = (longlong *)0x0;
    goto joined_r0x00023e89f91a;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc078);
  if (plVar10 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar9 = *plVar9 + -1;
    plVar10 = (longlong *)0x0;
    if (*plVar9 == 0) {
      plVar12 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      pcVar11 = (code *)0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar17 = 0x100;
      plVar9 = plStack_68;
      plVar13 = DAT_23ed6a4f8;
    }
    else {
      plVar12 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      pcVar11 = (code *)0x0;
      uVar17 = 0x100;
      plVar9 = plStack_68;
      plVar13 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e89f91a;
  }
  *(undefined4 *)(plVar4 + 5) = 0x100;
  pcStack_88 = pcVar1;
  plStack_80 = plVar10;
  pcVar11 = (code *)FUN_23e94ed00(param_1,plVar9,&pcStack_88);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  pcVar6 = _Py_NoneStruct_exref;
  lVar15 = DAT_23ed6cce8;
  if (pcVar11 == (code *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    uVar17 = 0x100;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e89f91a;
  }
  lVar3 = *(longlong *)(param_1 + 0x10);
  iVar8 = *(int *)(lVar3 + 0x1410);
  plVar9 = *(longlong **)(DAT_23ed6cce8 + 0x20);
  *plVar9 = *plVar9 + 1;
  if (pcVar11 == pcVar6) {
    if (iVar8 == 0) {
      plVar10 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
      plVar9 = *(longlong **)(lVar15 + 0x20);
    }
    else {
      *(int *)(lVar3 + 0x1410) = iVar8 + -1;
      plVar10 = *(longlong **)(lVar3 + 0x1190 + (longlong)(iVar8 + -1) * 8);
      *plVar10 = 1;
    }
    lVar15 = *(longlong *)(lVar15 + 0x28);
    plVar10[2] = 0;
    plVar10[4] = (longlong)plVar9;
    plVar10[5] = lVar15;
    lVar15 = *(longlong *)(param_1 + 0x38);
    plVar10[3] = 1;
    lVar3 = *(longlong *)(lVar15 + 8);
    plVar9 = *(longlong **)(lVar3 + 0x28);
    plVar4 = (longlong *)plVar9[2];
    *(undefined8 *)(lVar15 + 8) = *(undefined8 *)(lVar3 + 0x30);
    *(undefined4 *)(plVar9 + 8) = 0xffffffff;
    if (plVar4 != (longlong *)0x0) {
      plVar9[2] = 0;
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))();
      }
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *(longlong *)pcVar6 = *(longlong *)pcVar6 + -1;
    lVar15 = *(longlong *)pcVar6;
    plVar9[0xf] = 0;
    if (lVar15 == 0) {
      (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
    }
LAB_23e89f5c2:
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    lVar15 = *(longlong *)pcVar1;
    *(longlong *)pcVar1 = lVar15 + -1;
    if (lVar15 + -1 != 0) {
      return plVar10;
    }
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
    return plVar10;
  }
  if (iVar8 == 0) {
    plVar10 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
    plVar9 = *(longlong **)(lVar15 + 0x20);
  }
  else {
    *(int *)(lVar3 + 0x1410) = iVar8 + -1;
    plVar10 = *(longlong **)(lVar3 + 0x1190 + (longlong)(iVar8 + -1) * 8);
    *plVar10 = 1;
  }
  lVar15 = *(longlong *)(lVar15 + 0x28);
  plVar10[2] = 0;
  plVar10[3] = 1;
  plVar10[4] = (longlong)plVar9;
  plVar10[5] = lVar15;
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc278);
  if (plVar12 == (longlong *)0x0) goto LAB_23e89f650;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc0f0);
  if (plVar9 == (longlong *)0x0) {
LAB_23e89fa50:
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar12 = *plVar12 + -1;
    plVar9 = plStack_68;
    uVar18 = auStack_78._0_8_;
    uVar19 = auStack_78._8_8_;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      plVar9 = plStack_68;
      uVar18 = auStack_78._0_8_;
      uVar19 = auStack_78._8_8_;
    }
  }
  else {
    plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar9,_DAT_23eedc148);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e89fa50;
    *(undefined4 *)(plVar4 + 5) = 0x107;
    pcStack_88 = pcVar11;
    plStack_80 = plVar13;
    plVar9 = (longlong *)FUN_23e94ed00(param_1,plVar12,&pcStack_88);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar9 == (longlong *)0x0) {
LAB_23e89f650:
      plVar9 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = *(undefined8 *)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar19 = *(undefined8 *)(param_1 + 0x68);
    }
    else {
      plVar13 = (longlong *)FUN_23a388310(plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar13 == (longlong *)0x0) goto LAB_23e89f650;
      plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
      if ((plVar14 == (longlong *)0x0) &&
         (plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2), plVar14 == (longlong *)0x0))
      {
        plVar12 = (longlong *)0x0;
      }
      else {
        plVar12 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
        if (((plVar12 != (longlong *)0x0) ||
            (plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2), plVar12 != (longlong *)0x0
            )) && (cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar13,2), cVar7 != '\0')) {
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          lVar15 = FUN_23e8db270();
          if (lVar15 == 0) {
            FUN_23e915740(param_1,auStack_78,_DAT_23eedc280);
            uVar17 = 0x108;
            plVar9 = plStack_68;
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e89f91a;
          }
          iVar8 = FUN_23e97d0c0(plVar14,lVar15);
          uVar18 = _DAT_23eedc288;
          if (iVar8 == -1) {
            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            uVar17 = 0x108;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = DAT_23ed6a4f8;
            goto joined_r0x00023e89f91a;
          }
          if (iVar8 == 1) {
            plVar9 = (longlong *)_PyDict_NewPresized(2);
            PyDict_SetItem(plVar9,uVar18,plVar14);
            PyDict_SetItem(plVar9,_DAT_23eedc290,plVar12);
            PyDict_SetItem(plVar10,_DAT_23eedc148,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc278);
          if (plVar13 == (longlong *)0x0) goto LAB_23e89fca0;
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc0f0);
          if (plVar9 == (longlong *)0x0) {
LAB_23e89fc30:
            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            plVar9 = plStack_68;
            uVar18 = auStack_78._0_8_;
            uVar19 = auStack_78._8_8_;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
              plVar9 = plStack_68;
              uVar18 = auStack_78._0_8_;
              uVar19 = auStack_78._8_8_;
            }
          }
          else {
            plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar9,_DAT_23eedc168);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar16 == (longlong *)0x0) goto LAB_23e89fc30;
            *(undefined4 *)(plVar4 + 5) = 0x10c;
            pcStack_88 = pcVar11;
            plStack_80 = plVar16;
            plVar9 = (longlong *)FUN_23e94ed00(param_1,plVar13,&pcStack_88);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (plVar9 == (longlong *)0x0) {
LAB_23e89fca0:
              uVar18 = *(undefined8 *)(param_1 + 0x60);
              plVar9 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar19 = *(undefined8 *)(param_1 + 0x68);
            }
            else {
              plVar13 = (longlong *)FUN_23a388310(plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar13 == (longlong *)0x0) goto LAB_23e89fca0;
              plStack_a0 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
              if ((plStack_a0 == (longlong *)0x0) &&
                 (plStack_a0 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2),
                 plStack_a0 == (longlong *)0x0)) {
                plStack_98 = (longlong *)0x0;
              }
              else {
                plStack_98 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                if (((plStack_98 != (longlong *)0x0) ||
                    (plStack_98 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
                    plStack_98 != (longlong *)0x0)) &&
                   (cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar13,2), cVar7 != '\0')) {
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *plStack_a0 = *plStack_a0 + 1;
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  lVar15 = *plStack_a0;
                  *plStack_a0 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
                  }
                  *plStack_98 = *plStack_98 + 1;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  lVar15 = *plStack_98;
                  *plStack_98 = lVar15 + -1;
                  if (lVar15 + -1 == 0) {
                    (**(code **)(plStack_98[1] + 0x30))(plStack_98);
                  }
                  lVar15 = FUN_23e8db270();
                  plVar12 = plStack_98;
                  plVar14 = plStack_a0;
                  if (lVar15 == 0) {
                    FUN_23e915740(param_1,auStack_78,_DAT_23eedc280);
                    uVar17 = 0x10d;
                    plVar9 = plStack_68;
                    plVar13 = DAT_23ed6a4f8;
                    goto joined_r0x00023e89f91a;
                  }
                  iVar8 = FUN_23e97d0c0(plStack_a0,lVar15);
                  uVar18 = _DAT_23eedc288;
                  if (iVar8 == -1) {
                    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uVar17 = 0x10d;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plVar13 = DAT_23ed6a4f8;
                    goto joined_r0x00023e89f91a;
                  }
                  if (iVar8 == 1) {
                    plVar9 = (longlong *)_PyDict_NewPresized(2);
                    PyDict_SetItem(plVar9,uVar18,plStack_a0);
                    PyDict_SetItem(plVar9,_DAT_23eedc290,plStack_98);
                    PyDict_SetItem(plVar10,_DAT_23eedc168,plVar9);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                  }
                  plVar12 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc278);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e89fef3;
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc0f0);
                  if (plVar9 == (longlong *)0x0) {
LAB_23e89ff31:
                    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar12 = *plVar12 + -1;
                    plVar9 = plStack_68;
                    uVar18 = auStack_78._0_8_;
                    uVar19 = auStack_78._8_8_;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0(plVar12);
                      plVar9 = plStack_68;
                      uVar18 = auStack_78._0_8_;
                      uVar19 = auStack_78._8_8_;
                    }
                  }
                  else {
                    plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar9,_DAT_23eedc180);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e89ff31;
                    *(undefined4 *)(plVar4 + 5) = 0x111;
                    pcStack_88 = pcVar11;
                    plStack_80 = plVar13;
                    plVar9 = (longlong *)FUN_23e94ed00(param_1,plVar12,&pcStack_88);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if (plVar9 == (longlong *)0x0) {
LAB_23e89fef3:
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar18 = *(undefined8 *)(param_1 + 0x60);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar19 = *(undefined8 *)(param_1 + 0x68);
                    }
                    else {
                      plVar13 = (longlong *)FUN_23a388310(plVar9);
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      if (plVar13 == (longlong *)0x0) goto LAB_23e89fef3;
                      plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if ((plVar14 == (longlong *)0x0) &&
                         (plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2),
                         plVar14 == (longlong *)0x0)) {
                        plVar12 = (longlong *)0x0;
                      }
                      else {
                        plVar12 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                        if (((plVar12 != (longlong *)0x0) ||
                            (plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
                            plVar12 != (longlong *)0x0)) &&
                           (cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar13,2), cVar7 != '\0')) {
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          *plVar14 = *plVar14 + 1;
                          lVar15 = *plStack_a0;
                          *plStack_a0 = lVar15 + -1;
                          if (lVar15 + -1 == 0) {
                            (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          *plVar12 = *plVar12 + 1;
                          lVar15 = *plStack_98;
                          *plStack_98 = lVar15 + -1;
                          if (lVar15 + -1 == 0) {
                            (**(code **)(plStack_98[1] + 0x30))(plStack_98);
                          }
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          lVar15 = FUN_23e8db270();
                          if (lVar15 == 0) {
                            FUN_23e915740(param_1,auStack_78,_DAT_23eedc280);
                            uVar17 = 0x112;
                            plVar9 = plStack_68;
                            plVar13 = DAT_23ed6a4f8;
                          }
                          else {
                            iVar8 = FUN_23e97d0c0(plVar14,lVar15);
                            uVar18 = _DAT_23eedc288;
                            if (iVar8 != -1) {
                              if (iVar8 == 1) {
                                plVar9 = (longlong *)_PyDict_NewPresized(2);
                                PyDict_SetItem(plVar9,uVar18,plVar14);
                                PyDict_SetItem(plVar9,_DAT_23eedc290,plVar12);
                                PyDict_SetItem(plVar10,_DAT_23eedc180,plVar9);
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  FUN_23a334bc0(plVar9);
                                }
                              }
                              lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                              plVar9 = *(longlong **)(lVar15 + 0x28);
                              plVar4 = (longlong *)plVar9[2];
                              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                   *(undefined8 *)(lVar15 + 0x30);
                              *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                              if (plVar4 != (longlong *)0x0) {
                                plVar9[2] = 0;
                                *plVar4 = *plVar4 + -1;
                                if (*plVar4 == 0) {
                                  (**(code **)(plVar4[1] + 0x30))();
                                }
                              }
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              plVar9[0xf] = 0;
                              *plVar10 = *plVar10 + 1;
                              *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
                              if (*(longlong *)pcVar11 == 0) {
                                (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
                              }
                              *plVar10 = *plVar10 + -1;
                              if (*plVar10 == 0) {
                                (**(code **)(plVar10[1] + 0x30))(plVar10);
                              }
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                (**(code **)(plVar14[1] + 0x30))(plVar14);
                              }
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                              }
                              goto LAB_23e89f5c2;
                            }
                            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            plVar9 = *(longlong **)(param_1 + 0x70);
                            uVar17 = 0x112;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            plVar13 = DAT_23ed6a4f8;
                          }
                          goto joined_r0x00023e89f91a;
                        }
                      }
                      plVar9 = plStack_68;
                      uVar19 = auStack_78._8_8_;
                      uVar18 = auStack_78._0_8_;
                      plStack_68 = (longlong *)0x0;
                      auStack_78 = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      plStack_68 = (longlong *)0x0;
                      auStack_78._0_8_ = 0;
                      auStack_78._8_8_ = 0;
                      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0))
                      {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0))
                      {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                    }
                  }
                  uVar17 = 0x111;
                  plVar12 = plStack_98;
                  auStack_78._0_8_ = uVar18;
                  auStack_78._8_8_ = uVar19;
                  plVar13 = DAT_23ed6a4f8;
                  plVar14 = plStack_a0;
                  goto joined_r0x00023e89f91a;
                }
              }
              plVar9 = plStack_68;
              uVar19 = auStack_78._8_8_;
              uVar18 = auStack_78._0_8_;
              plStack_68 = (longlong *)0x0;
              auStack_78 = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              plStack_68 = (longlong *)0x0;
              auStack_78._0_8_ = 0;
              auStack_78._8_8_ = 0;
              if ((plStack_a0 != (longlong *)0x0) &&
                 (lVar15 = *plStack_a0, *plStack_a0 = lVar15 + -1, lVar15 + -1 == 0)) {
                (**(code **)(plStack_a0[1] + 0x30))();
              }
              if ((plStack_98 != (longlong *)0x0) &&
                 (lVar15 = *plStack_98, *plStack_98 = lVar15 + -1, lVar15 + -1 == 0)) {
                (**(code **)(plStack_98[1] + 0x30))();
              }
            }
          }
          uVar17 = 0x10c;
          auStack_78._0_8_ = uVar18;
          auStack_78._8_8_ = uVar19;
          plVar13 = DAT_23ed6a4f8;
          goto joined_r0x00023e89f91a;
        }
      }
      plVar9 = plStack_68;
      uVar19 = auStack_78._8_8_;
      uVar18 = auStack_78._0_8_;
      plStack_68 = (longlong *)0x0;
      auStack_78 = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plStack_68 = (longlong *)0x0;
      auStack_78._0_8_ = 0;
      auStack_78._8_8_ = 0;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  uVar17 = 0x107;
  plVar12 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  auStack_78._0_8_ = uVar18;
  auStack_78._8_8_ = uVar19;
  plVar13 = DAT_23ed6a4f8;
joined_r0x00023e89f91a:
  DAT_23ed6a4f8 = plVar13;
  plStack_68 = plVar9;
  if (plVar9 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar15 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar17;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar3 = plVar13[-1];
    puVar5 = *(undefined8 **)(lVar15 + 8);
    *puVar5 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar9 = plVar13;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))(plStack_68);
    }
  }
  else if ((longlong *)plVar9[3] != plVar4) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar15 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar17;
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
    lVar3 = plVar13[-1];
    puVar5 = *(undefined8 **)(lVar15 + 8);
    *puVar5 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar13[2] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    plVar9 = plVar13;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
  plStack_68 = plVar9;
  FUN_23e8bba40(plVar4,"oooooo",plVar2,pcVar1,pcVar11,plVar10,plVar14,plVar12);
  if (_DAT_23eede470 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eede470 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar15 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar4 = plStack_68;
  uVar19 = auStack_78._8_8_;
  uVar18 = auStack_78._0_8_;
  plVar9[0xf] = 0;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((pcVar11 != (code *)0x0) &&
     (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  auStack_78 = CONCAT88(uVar19,uVar18);
  *plVar2 = *plVar2 + -1;
  plStack_68 = plVar4;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar15 = *(longlong *)pcVar1;
  *(longlong *)pcVar1 = lVar15 + -1;
  if (lVar15 + -1 == 0) {
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,plStack_68);
  return (longlong *)0x0;
}
